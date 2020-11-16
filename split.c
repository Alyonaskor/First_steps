#include <stdio.h>
#include <stdlib.h>

typedef struct s_split_next 
{
    size_t start;
    size_t length;
}              t_split_next;

static char **alloc_mem(char const *str, char ch)
{
    char **split;
    size_t res = 0;
    size_t i = 0;

    while( str[i])
    {
        if (str[i] == ch)
            res++;
        i++;
    }
    split = (char**)malloc(sizeof(char*)*(res + 2));
    if(!split)
        return (NULL);
    return (split);
}

char *innerhard(const char *str, size_t start, size_t length)
{
    char *word;
    size_t i = 0;
    size_t j = 0;
    word = (char*)malloc(sizeof(char) * (length + 1));
    if(!word)
        return (NULL);
    while(str[i]) 
    {
        if(i >= start && j <= length)
        {
            word[j] = str[i];
            j++;
        }
        i++;
    }
    word[j] = '\0';
    return (word);
}

void *free_all_split(char **split, size_t length)
{
    size_t i = 0;
    while(i < length)
    {
        free(split[i]);
        i++;
    }
    free(split);
    return (NULL);
}

static void *write_or_free( char **split, char const *str, t_split_next *st, t_split_next *lt)
{
    split[lt->length] = innerhard(str, st->start, st->length);
    if(!split[lt->length])
        return (free_all_split(split, lt->length));
    lt->length++;
    return (split);
}

static void *split_by_char(char **split, char const *str, char ch)
{
    size_t i = 0;
    t_split_next st;
    t_split_next lt;
    lt.length = 0;
    lt.start = 0;

    while(str[i])
    {
        if(str[i] == ch)
        {
            st.start = lt.start;
            st.length = i - lt.start;
            if (i > lt.start && !write_or_free(split, str, &st, &lt))
                return (NULL);
            lt.start = i + 1;
        }
        i++;
    }
    st.start = lt.start;
    st.length = i - lt.start;
    if (i > lt.start && !write_or_free(split, str, &st, &lt))
        return (NULL);
    split[lt.length] = 0; 
    return (split);
}

char **split(char const *str, char ch)
{
    char **split;

    if(!(split = alloc_mem(str,ch)))
        return (NULL);
    if(!(split_by_char(split, str, ch)))
        return (NULL);

    return (split);
}

int main()
{
    char const str[100] = "Divide this sentance into parts";
    char ch = ' ';
    char **res;
    res = split(str, ch);
    for(size_t i = 0; res[i]; i++)
        printf("%s\n", res[i]);
    return 0;
}
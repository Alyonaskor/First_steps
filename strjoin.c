#include <stdio.h>
#include <stdlib.h>
int main()
{
    char str1[] = "The first message";
    char str2[] = "12345 12345";
    int i = 0;
    int j = 0;
    char *str;
    while(str1[i])
    i++;
    while(str2[j])
    j++;
    str = (char*) malloc(sizeof(char) * (i + j));
    if(!str)
    return 0;
    i = 0;
    j = 0;
    while (str1[i])
    {
    str[i] = str1[i];
    i++;
    }
    while (str2[j])
    {
        str[i] = str2[j];
        i++;
        j++;
    }
    str[i] = '\0';
    printf("%s", str);

    
    return 0;
}
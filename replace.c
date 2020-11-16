// замена нескольких элементов строки
#include <stdio.h>
int main () 
{
char str[50] = "Replaceble characters";
int i = 0;
while(str[i]) 
{

    if (!(str[i] == 'c' && str[i + 1] == 'h'))
        i++;
    else 
    {
        str[i] = 'z';
        str[i+1] = 'x';
        break;
    }
}
printf("%s", str);

    return 0;
} 

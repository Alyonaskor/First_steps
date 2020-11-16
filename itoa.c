//преобпазование int в char*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* char *itoa(int n)
{
char *str;
int m;
bool sign;
if (n < 0) 
{
    sign = true;
    n = -n;
}
else sign = false; //n < 0 ? sign = true, n = -n : sign = false

m = n;
size_t i = 0;
while(m/10)
{
    m /= 10;
   i++; 
}
i++;
if (sign) 
    str = (char*)malloc(sizeof(char) * (i + 1));
else
    str = (char*)malloc(sizeof(char) * i);
if(!str)
    return (NULL);
if(sign == false)
{
    str[i] = '\0';
    while(i-- > 0)
    {
        str[i] = n%10 + '0';
        n/=10;
    }
}
else 
{
    str[0] = '-';
    str[i + 1] = '\0';
    while(i > 0)
    {
        str[i] = n%10 + '0';
        n/=10;
        i--;
    }
}
    return str;
}*/

char *itoa(int n)
{
char *str;
int m;
bool sign;
if (n < 0) 
    sign = true;
else sign = false; //n < 0 ? sign = true, n = -n : sign = false
m = n;
size_t i = 0;
while(m/10)
{
    m /= 10;
   i++; 
}
i++;
if (sign) 
    str = (char*)malloc(sizeof(char) * (i + 1));
else
    str = (char*)malloc(sizeof(char) * i);
if(!str)
    return (NULL);
if(sign == false)
{
    str[i] = '\0';
    while(i-- > 0)
    {
        str[i] = n%10 + '0';
        n/=10;
    }
}
else 
{

    str[0] = '-';
    str[i + 1] = '\0';
    while(i > 0)
    {
        str[i] = n%10 + '0';
        n/=10;
        i--;
    }
}
    return str;
}

int main()
{
    int n = -34; //-2147483648; //2147483647 
    char *str;
    str = itoa(n);
    printf("%s", str);
    return 0;
}


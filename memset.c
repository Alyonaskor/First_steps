#include <stdio.h>
#include <string.h>
int main() {
    char str_test[50] = "sjhfglja";
    char str[50] = "sjhfglja";
    char symbol = 'A';
    int n = 5;
    int i = 0;
    if( n > (int)strlen(str))
    return 0;
    while(str[i] && i < n) 
    {
        str[i] = symbol;
        i++;
    }
    printf("%s \n", str);

    memset(str_test, 'B', 5);
    printf("%s ", str_test);

    return 0;
}
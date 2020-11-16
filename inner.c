#include <stdio.h>
int main() {
    char str[] = "owseHelloHellk";
    char strinner[] = "Hellok";
    int i = 0
    int j = 0;
    while(str[i])
    {
        if(str[i] == strinner[j])
        {
            printf("%c", str[i]);
            j++;
        }
        i++;
        
    }

    return 0;
}
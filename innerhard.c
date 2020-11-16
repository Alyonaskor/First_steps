#include <stdio.h>
int main() {
    char str[] = "owseHelloHellok";
    char strinner[] = "Hellok";
    int i = 0;
    int j = 0;
    int k = 0;
    while(str[i])
    {
        if(str[i] == strinner[j])
        {
            k = i;
            while(strinner[j])
            {
                if(str[i] == strinner[j])
                {
                    j++;
                    i++;
                }
                else break;
                
            }
            if(strinner[j] == '\0') 
            {
                printf("%s", strinner);
                break;

            }
        i = k + 1;
        j = 0;
        }
        else 
        i++;
    }
    return 0;
}
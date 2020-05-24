#include<stdio.h>

int strStr(char * haystack, char * needle)
{
    int i = 0, j = 0;
    if (needle[j] == '\0') return 0;
    if (haystack[i] == '\0') return -1;

    int wasMatched = 0;
    

    while(haystack[i] != '\0' && needle[j] != '\0')
    {
        if (haystack[i] != needle[j])
        {
            if (!wasMatched) i++;
            else
            {
                i = i-(j-1);
                wasMatched = 0;
            }
            j = 0;
        }
        else
        {
            wasMatched = 1;
            i++;
            j++;
        }
    }
    if (needle[j] == '\0') return i-j;
    else return -1;
}

int main()
{
    char haystack[] = "mississippi";
    char needle[] = "issip";
    printf("%d\n", strStr(haystack, needle)); 
}
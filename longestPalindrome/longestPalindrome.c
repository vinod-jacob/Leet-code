#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* longestPalindrome(char * s)
{
    int ptr = 0; int longest = 0, headposition = 0, currentlength = 0;
    int ptr_l = 0, ptr_r = 0;
    int i = 0;
    char* ret = (char*)malloc(sizeof(char));
    ret[0] = '\0';
     while (s[ptr] != '\0')
    {
        ptr_l = ptr;
        ptr_r = ptr + 1;
        currentlength = 1;

        while ((s[ptr_l] == s[ptr_r]) && (ptr_l >= 0) && (s[ptr_r] != '\0'))
        {
            //found a mirror palindrome
            currentlength = (ptr_r - ptr_l) + 1;
            if (longest < currentlength)
            {
                longest = currentlength;
                headposition = ptr_l;
            }
            ptr_l--; ptr_r++;
        }
        longest = longest > currentlength ? longest : currentlength;
        ptr++;
    }
    ret = realloc(ret, (longest + 1) * sizeof(char));
    while (i < longest)
    {
        ret[i] = s[headposition];
        ret[i+1] = '\0';
        i++, headposition++;
    }
    return ret;
}

void main()
{
    char s[] = "";
    printf("%s\n",longestPalindrome(s));
}
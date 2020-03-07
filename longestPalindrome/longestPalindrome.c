#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* longestPalindrome(char * s)
{
    int ptr = 0; int longest = 0, headposition = 0, currentlength = 0;
    int ptr_l = 0, ptr_r = 0;
    int i = 0;
    char* ret;
     while (s[ptr] != '\0')
    {
        currentlength = 1; //each time a character is not null, we have a single character palindrome

        /*first condition to ensure we don't fall off the earth walking backwards.
         We don't check to see if we fall off walking forwards, coz atleast there is
         going to be a null character there to stop us*/
        if ((ptr-1 >= 0 ) && (s[ptr - 1] == s[ptr + 1]))
        { //found a pivot point
            ptr_l = ptr - 1;
            ptr_r = ptr + 1;

            /*making the check to see if ptr_l is greater than 0 first, so that
            we don't create a runtime error by accessing s[-1] (conditional short-circuiting
            helps us out)*/
            while ((ptr_l >= 0) && (s[ptr_r] != '\0') && (s[ptr_l] == s[ptr_r]))
            {
                currentlength = (ptr_r - ptr_l) + 1;
                if (longest < currentlength)
                {
                    longest = currentlength;
                    headposition = ptr_l;
                }
                ptr_l--; ptr_r++;
            }
        } //end pivot pallindrome case

        if (s[ptr] == s[ptr + 1]) //mirror pallindrom case
        {
            ptr_l = ptr;
            ptr_r = ptr + 1;

            while ((ptr_l >= 0) && (s[ptr_r] != '\0') && (s[ptr_l] == s[ptr_r]))
            {
                currentlength = (ptr_r - ptr_l) + 1;
                if (longest < currentlength)
                {
                    longest = currentlength;
                    headposition = ptr_l;
                }
                ptr_l--; ptr_r++;
            }
        }
        ptr++;
    }
    longest = longest > currentlength ? longest : currentlength; //this to catch those input strings that are only a single character
    ret = (char*)malloc((longest+1) * sizeof(char)); //longest + 1 to include the null character at the end
    
    /*populate ret with our longest pallindromic substring*/
    ret[0] = '\0';
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
    char s[] = "cbbd";
    printf("%s\n",longestPalindrome(s));
}
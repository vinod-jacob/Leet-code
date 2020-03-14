#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

bool isPalindrome(int x)
{
    bool ret = true;
    int rev = 0, d = 0;
    int num = x;

    if (x < 0)
    {
        ret = false;
    }
    else
    {
        while (x != 0)
        {
            d = x%10;
            x = x/10;
            if (rev >= INT32_MAX/10)
            {
                return false;
            }
            else
            {
                rev = rev * 10 + d;
            }
        }

        if (rev == num)
        {
            ret = true;
        }
        else
        {
            ret = false;
        }
    }
    return ret;
}

void main(int argc, char **argv)
{
    while (--argc > 0)
    {
        printf("%d", isPalindrome(atoi(*++argv)));
    }
}
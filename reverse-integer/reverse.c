#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

int reverse(int x)
{
    int d = 0;
    int num = 0, it = 0;
    int sign = x < 0? -1 : 1;
    bool of = false;
    /*we have to check x != 0 and not x > 0 (after multiplying with sign, in order to operate with positive numbers alone,
    because of the input INT32_MIN would overflow when blindly converting to postive*/
    while (x != 0)
    {
        d = x % 10;
        x = x /10;
        if ((num > INT32_MAX/10) || (num < INT32_MIN/10))
        {
            of = true;
        }
        else if (num == INT32_MAX || num == INT32_MIN)
        {
            if ((sign == 1) && (d > 7)) //incase of +ve numbers
                of = true;
            else if ((sign == -1) && (d > 8)) //in case of -ve numbers
                of = true;
        }

        if (!of)
        {
            num = num * 10 + d;
        }
        else
        {
            return 0;
        }
        
    }
    return num;
}

void main()
{
    printf("%d\n", reverse(INT32_MIN));
}
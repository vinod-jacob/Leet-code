#include<stdio.h>
#include <stdbool.h>
#include <stdint.h>

int myAtoi(char *str)
{
    int num = 0, ptr = 0, sign = 1, d = 0, tracker = 0;
    bool sendRet = false;

    while (str[ptr] != '\0')
    {
        sendRet = false;
        if (str[ptr] == ' ' && tracker == 0) //discard all leading whitespaces and move on quickly
        {
            ptr++;
        }
        else
        {
            switch(str[ptr])
            {
                case '1':
                    d = 1; tracker = 1; break;
                case '2':
                    d = 2; tracker = 1; break;
                case '3':
                    d = 3; tracker = 1; break;
                case '4':
                    d = 4; tracker = 1; break;
                case '5':
                    d = 5; tracker = 1; break;
                case '6':
                    d = 6; tracker = 1; break;
                case '7':
                    d = 7; tracker = 1; break;
                case '8':
                    d = 8; tracker = 1; break;
                case '9':
                    d = 9; tracker = 1; break;
                case '0':
                    d = 0; tracker = 1; break;
                case '+':
                    if (tracker == 0)
                    {
                        sign = 1; tracker = 2; break; //only once should a sign appear before intergers. Therfore tracker updated to 2
                    }
                    else if (tracker == 1) // a sign after integers. Return our number
                    {
                        return num*sign;
                    }
                    else
                    {
                        return 0; //indicates tracker == 2. Double sign characters, return 0
                    }
                case '-':
                    if(tracker == 0)
                    {
                        sign = -1; tracker = 2; break; //only once should a sign appear before intergers. Therfore tracker updated to 2
                    }
                    else if (tracker == 1) //indicates a sign after all integers
                    {
                        num = num*sign;
                        sendRet = true;
                    }
                    else
                    {
                        num = 0;
                        sendRet = true;
                    }
                    
                default:
                    if (tracker == 0)
                    {
                        //some character immediately after whitespaces. Return 0
                        num = 0;
                        sendRet = true;
                    }
                    else if (tracker == 1)
                    {
                        //found a charater after integers. We should end it here
                        num = num*sign;
                        sendRet = true;
                    }
                    else
                    {
                        //a white space after a sign character. Return 0
                        num = 0;
                        sendRet = true;
                    }
                    
            }
            if (tracker == 1 && !sendRet) //go ahead only if we encountered a number
            {
                if ((sign == 1) && (num > INT32_MAX/10))
                {
                    num = INT32_MAX;
                    sendRet = true;
                }
                else if ((sign == -1 ) && (num*sign < INT32_MIN/10))
                {
                    num = INT32_MIN;
                    sendRet = true;
                }
                else if ((sign == 1 ) && (num == INT32_MAX/10))
                {
                    if (d <=7) 
                    {
                        num = num*10 + d;
                         sendRet = true;
                    }
                    else
                    {
                        num = INT32_MAX;
                        sendRet = true;
                    }
                }
                else if ((sign == -1) && (num*sign == INT32_MIN/10))
                {
                    if (d <= 8)
                    {
                        num = sign*num*10 - d;
                        sendRet = true;
                    }
                    else
                    {
                     num  = INT32_MIN;
                     sendRet = true;
                    } 
                }
                else
                {
                    num = num * 10 + d;
                }
            }
            if (!sendRet)
                ptr++;
            else
                break;
        }
    }
    if ((sign == -1) && (num >= 0))
        num = num * sign;
    return num;
}

void main(int argc, char **argv)
{
    while (--argc > 0)
    {
        printf("%d", myAtoi(*++argv));
    }
    //char s[] = {'p','w','w','k','e','w','\0'};
    //char s[] = {'d', 'v', 'd', 'f', '\0'};
    //char s[] = {'a', 'a', 'b', 'a', 'a', 'b', '!', 'b', 'b', '\0'};
    //char s[] = {'b', 'b', 'b', 'b', 'b'};
    //char s[] = {'b'};
}

/* void main()
{
    char s[] = "   0000000000012345678";
    printf("%d\n", myAtoi(s));
} */
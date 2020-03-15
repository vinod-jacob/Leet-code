#include <stdio.h>
#include <stdbool.h>

int romanToInt(char * s)
{
    int ptr = 0;
    int num = 0;
    while (s[ptr] != '\0')
    {
        switch(s[ptr])
        {
            case 'M':
                num += 1000;
                ptr++;
                break;
            case 'D':
                num += 500; ptr++; break;
            case 'C':
                if ( (s[ptr+1] != '\0') && (s[ptr+1]=='M') )
                {
                    num += 900;
                    ptr +=2;
                    break;
                }
                else if ( (s[ptr+1] != '\0') && (s[ptr+1]=='D') )
                {
                    num += 400;
                    ptr +=2;
                    break;
                }
                else
                {
                    num += 100;
                    ptr++;
                    break;
                }
            case 'L':
                num += 50; ptr++; break;
            case 'X':
                if ((s[ptr+1] != '\0') && (s[ptr+1]=='C'))
                {
                    num += 90;
                    ptr +=2;
                    break;
                }
                else if ( (s[ptr+1] != '\0') && (s[ptr+1]=='L') )
                {
                    num += 40;
                    ptr +=2;
                    break;
                }
                else
                {
                    num +=10;
                    ptr++;
                    break;
                }
            case 'V':
                num +=5; ptr++; break;
            case 'I':
                if ((s[ptr+1] != '\0') && (s[ptr+1]=='X'))
                {
                    num += 9;
                    ptr +=2;
                    break;
                }
                else if((s[ptr+1] != '\0') && (s[ptr+1]=='V'))
                {
                    num += 4;
                    ptr +=2;
                    break;
                }
                else
                {
                    num += 1;
                    ptr++;
                    break;
                }
        }
    }
    return num;
}


void main()
{
    char s[] = "IV";
    printf("%d\n", romanToInt(s));
}
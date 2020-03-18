#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isMatch(char * s, char * p)
{
    int sp = 0, pp = 0;
    int dragbackCounterfordot = 0;
    bool isMatch = true; bool zoom = false;
    char ch = '\0';

    while ((s[sp] != '\0') || (p[pp] != '\0'))
    {   
        if (s[sp] == p[pp] || p[pp] == '.')
        { 
            if ( !zoom && s[sp] == '\0' && p[pp] == '.' && p[pp+1] != '*' )
            {
                isMatch = false;
                break;
            }
            if (s[sp] != '\0') sp++;
            if (p[pp] != '\0') pp++;
        }
        else if ( (s[sp] == '\0') && (p[pp] == ch))
        {
            pp++;
        }
        else if (zoom && (p[pp] == '\0') && (s[sp] == ch || p[pp-1] == '.')) //drag back p[pp] to the previous occurence of ch
        {
            if (s[sp] == ch)
            {
                while (pp > 0 && p[pp] != ch)
                {
                    if (pp != 0) pp--;
                }
            }
            else if (p[pp -1] == '.')
            {
                if(dragbackCounterfordot <= strlen(s))
                {
                    if (pp - 1 > 0) pp --;
                    dragbackCounterfordot++;
                }
            }
        }
        else if ( p[pp] != '\0' && p[pp+1] != '\0' && p[pp+1] == '*')
        {
            pp += 2;
        }
        else if ( (pp - 1 >= 0) && (p[pp] == '*'))
        {
            if (s[sp] == p[pp-1])
            {
                while( (s[sp] != '\0') && (s[sp] == p[pp-1]))
                {
                    if (s[sp] != '\0') sp++;
                }

                ch = p[pp-1];
                if (p[pp] != '\0') pp++;
                while((p[pp] != '\0') && (ch == p[pp]))
                {
                    if(p[pp] != '\0') pp++;
                }
            }
            else if ((p[pp-1] == '.'))
            {
                if (p[pp] != '\0') pp++; if (sp > 0) sp--;
                while(s[sp] != p[pp])
                {
                    if (s[sp] != '\0')
                        sp++;
                    else
                        break;
                    zoom = true;
                }
                if (zoom) ch = s[sp];
            }
            else
            {
                if (p[pp] != '\0') pp++;
            }
        }
        else
        {
            isMatch = false;
            break;
        }
    }
    if ((s[sp] == '\0' && p[pp] != '\0') || (s[sp] != '\0' && p[pp] == '\0'))
    {
        isMatch = false;
    }
    return isMatch;
}

void main(int argc, char **argv)
{
    printf("%d", isMatch(argv[1], argv[2]));    
}


/* void main()
{
    printf("%d\n", isMatch("ba", ".*."));
} */
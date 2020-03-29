#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define INCSP if (s[sp]!='\0') {sp++;}
#define INCPP if (p[pp] != '\0') {pp++;}
#define DECPP if(pp >= 0) {pp--;} //else { ismatch = false; break;};
#define DECSP if(sp >= 0) {sp--;} //else { ismatch = false; break;};

#define MOVPP if(!isbacktrack) {INCPP} else {DECPP}
#define MOVSP if(!isbacktrack) {INCSP} else {DECSP}

bool isMatch(char * s, char * p)
{
    bool ismatch = true;
    int pp = 0 , sp = 0;
    char tmp = '\0';
    int ff = 0; bool isff = false;
    int pppos = 0, sppos = 0; bool isbacktrack = false;

    /* replace all .* with # and a* with A */
    int ptr = 0;
    while(p[ptr] != '\0')
    {
        if(p[ptr+1] == '*')
        {
            if (p[ptr] == '.')
            {
                p[ptr] = '#';
            }
            else
            {
                p[ptr] = toupper(p[ptr]);
            }
            ptr++;
            int i = ptr;
            while (p[i +1] != '\0')
            {
                p[i] = p[i +1];
                i++;
            }
            p[i] = '\0';
        }
        else
        {
            ptr++;
        }        
    }
    /* finish input string mod */

    while ( (isbacktrack && pp > pppos && sp >= sppos ) || (!isbacktrack && (s[sp] != '\0' || p[pp] != '\0')) )
    {
        if(isbacktrack && sp < 0)
        {
            ismatch = false;
            break;
        }

        if (s[sp] == p[pp] ) //this  is a proper character match
        {
            MOVSP;
            MOVPP;
        }
        else if (p[pp] == '.' && s[sp] != '\0') //proper dot match
        {
            MOVSP;
            MOVPP;
        }
        /* some character followed by * will be handled here*/
        else if ( isupper(p[pp]))
        {
            if (tolower(p[pp]) == s[sp])
            {
                tmp = s[sp];
                MOVPP;

                /* cases like aaaa and a*aa are handled through the next two while loops*/
                while (p[pp] == tmp)
                {
                    MOVPP;
                    MOVSP;
                }
                while (sp >= 0 && s[sp] == tmp)
                {
                    MOVSP;
                    /* here a fast forward has happenend, cases like aaa and a*c*a will
                        need the info set here on the next iteration*/
                        isff = true;
                        ff++;
                }
            }
            else if (tolower(p[pp]) != s[sp]) /*safely move on to the next character*/
            {
                MOVPP;
            }
        }
        else if (isff && (p[pp] == tmp) && (ff > 0)) /*fast forward cases*/
        {
            MOVPP;
            ff--;
        }
        else if (p[pp] == '#')
        {
            //MOVPP;
            if (p[pp+1] == '\0') //if pattern is already at \0, end it here
            {
                ismatch = true;
                break;
            }
            else
            {
                /* if .* are not the last two characters, but s[sp] is already at '\0',
                we have a mistmatch in our hands. end it with that */
                if(s[sp] == '\0')
                {
                    ismatch = false;
                    break;
                }
                else
                {
                    pppos = pp;
                    sppos = sp;
                    /* back tracking starts. flipping the pointers to the last characters*/
                    while (p[pp + 1] != '\0')
                    {
                        MOVPP;
                    }
                    while(s[sp + 1] != '\0')
                    {
                        MOVSP;
                    }
                    isbacktrack = true;
                }
                
            }
        }
        else
        {
            ismatch = false;
            break;
        }
    }
    if (isbacktrack && sp < sppos && pp > pppos)
    {
        ismatch = false;
    }

    return ismatch;
}

void main(int argc, char **argv)
{
    printf("%d", isMatch(argv[1], argv[2]));    
}


/* void main()
{
    char p[] = ".";
    printf("%d\n", isMatch("", p));
} */

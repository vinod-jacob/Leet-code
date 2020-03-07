#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* convert(char * s, int numRows)
{
    int ptr = 0; int runner = 0; 
    bool dir = false;
    struct Zigzag
    {
        char ret[10000];
        int length;
    }*zigzags;

    zigzags = (struct Zigzag*)malloc(numRows * sizeof(struct Zigzag));

    for(int it = 0; it < numRows; it++)
    {
        zigzags[it].length = 0;
    }

    while(s[ptr] != '\0')
    {
         zigzags[runner].ret[zigzags[runner].length++] = s[ptr];
         if ((runner == numRows-1) || (runner == 0))
         {
             dir = !dir;
         }
         if (dir)
         {
             if(runner < numRows-1)
                runner++;
         }
         else
         {  
             if(runner != 0)
                runner --;
         }
         ptr++;
    }
    char *ret = (char*)malloc((ptr+1) * sizeof(char));
    *ret = '\0';
    ptr = 0;
        for (int it = 0; it<numRows; it++)
    { 
        for(int j = 0; j<zigzags[it].length; j++)
        {
            ret[ptr++] = zigzags[it].ret[j];
            ret[ptr] = '\0';
        }
            
    }
    return ret;
}

void main()
{
    printf("%s\n", convert("", 1));
    //printf("%s\n", convert("CHATHOOTIMAAMAN", 1));
}

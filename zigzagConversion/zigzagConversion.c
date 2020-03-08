#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* convert(char * s, int numRows)
{
    int ptr = 0; int runner = 0; 
    bool dir = false;
    struct Zigzag
    {
        char* ret;
        int length;
    }*zigzags;

    zigzags = (struct Zigzag*)malloc(numRows * sizeof(struct Zigzag));

    for(int it = 0; it < numRows; it++)
    {
        zigzags[it].length = 0;
        zigzags[it].ret = (char*)malloc(sizeof(char));
        *zigzags[it].ret = '\0';
    }

    while(s[ptr] != '\0')
    {
         zigzags[runner].ret[zigzags[runner].length++] = s[ptr];
         zigzags[runner].ret = (char*)realloc((char*)zigzags[runner].ret, zigzags[runner].length+1);
         zigzags[runner].ret[zigzags[runner].length] = '\0';
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
    printf("%s\n", convert("PAYPALISHIRINGALLTHESHITEMPLOYEES", 3));
    //printf("%s\n", convert("CHATHOOTIMAAMAN", 1));
}
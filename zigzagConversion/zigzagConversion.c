#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>


char* convert(char * s, int numRows)
{
    int ptr = 0, runner = 0, length = 1, waterfallIncrementer = 0; 
    bool dir = false;
    char *ret = (char*)malloc(sizeof(char) * (strlen(s) + 1)); *ret = '\0';
    int *block = (int*)calloc(numRows, sizeof(int));
    
    while (s[ptr] != '\0')
    {
        length++;
        for(int shifter = length-2; shifter >= block[runner]; shifter--)
        {
            ret[shifter + 1] = ret[shifter];
        }
        ret[block[runner]] = s[ptr];
        waterfallIncrementer = runner;
        while(waterfallIncrementer < numRows)
        {
            block[waterfallIncrementer]++;
            waterfallIncrementer++;
        }
        if((runner == numRows-1) || (runner == 0))
        {
            dir = !dir;
        }
        if (numRows != 1)
        {
            if(dir)
                runner++;
            else
                runner--;
        }
        ptr++;
    }

    return ret;
}

void main()
{
    printf("%s\n", convert("A", 3));
    //printf("%s\n", convert("CHATHOOTIMAAMAN", 1));
}
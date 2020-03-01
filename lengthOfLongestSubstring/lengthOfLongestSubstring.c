#include <stdio.h>
#include <stdbool.h>

#define HERE() printf("%d - %s\n", __LINE__, __FUNCTION__ )

bool HeadNotAtEndOfString(char ch)
{
    bool ret = false;
    if (ch == '\0')
    {
        ret = false;
    }
    else
    {
        ret = true;
    }
    return ret;
}

bool ifSubstringContainsThisCharacter(char *substring, char ch)
{
    bool ret = false;
    for(int i = 0; substring[i] != '\0'; i++)
    {
        if(substring[i] == ch)
        {
            ret = true;
            break;
        }
    }
    return ret;
}

void addCharacterPointedByHead(char *substring, char ch)
{
    int i = 0;
    while(substring[i] != '\0')
    {
        i++;
    }
    substring[i] = ch;
}

int getCurrentLengthOfSubstring(char *substring)
{
    int i = 0;
    while (substring[i] != '\0')
    {
        i++;
    }
    return i;
}

void moveTailUntilDuplicateCharacterPlusOne(char *substring, char ch, int *tail)
{
    int i = 0;
    while (substring[i] != ch)
    {
        i++;
    }
    *tail = *tail + i + 1;
}

void flushSubstring(char *substring)
{
    for (int i = 0; substring[i] != '\0'; i++)
    {
        substring[i] = '\0';
    }
}

void updateSubstringUsingHeadAndTail(char *fullstring, char* substring, int head, int tail)
{
    int i = 0;
    while (tail != head)
    {
        substring[i] = fullstring[tail];
        i++; tail++;
    }
}

int lengthOfLongestSubstring(char* fullString)
{
    char substring[128] = {'\0'};
    int head = 0, tail = 0;
    int currentLengthOfSubstring = 0;
    int longestSubstring = 0;

    int q = 0;

    while(HeadNotAtEndOfString(fullString[head])) //constant time
    {
        //printf ("%d-------------------%s-----------------\n", q, fullString);
        //printf("HEAD1 ---> %c === %d\n", fullString[head], head);
        //printf("TAIL1 ---> %c === %d\n", fullString[tail], tail);
        //printf("SUBS1 ---> %s\n", substring);
        

        if ( !ifSubstringContainsThisCharacter(substring, fullString[head])) // O(N)
        {
            addCharacterPointedByHead(substring, fullString[head]); //O(N) --> but can be made constant time, using above step
        }
        else
        {
            //printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
            currentLengthOfSubstring = getCurrentLengthOfSubstring(substring); //O(N), but can be made constant time
            longestSubstring = currentLengthOfSubstring > longestSubstring ? currentLengthOfSubstring : longestSubstring; //O(1)
            //printf("current Tail --> %c === %d\n", fullString[tail], tail);   
            moveTailUntilDuplicateCharacterPlusOne(substring, fullString[head], &tail); //O(N) -> can be made O(1)
            //printf("new Tail --> %c === %d\n", fullString[tail], tail);
            //printf("current Substring ---> %s\n", substring);
            flushSubstring(substring); //O(1)
            updateSubstringUsingHeadAndTail(fullString, substring, head, tail); //O(N)
            //printf("new Substring 1 ---> %s\n", substring);
            addCharacterPointedByHead(substring, fullString[head]); //constant time
            //printf("new Substring 2 ---> %s\n", substring);
            //printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
        }
        head++; //constant time
        //printf("HEAD2 ---> %c === %d\n", fullString[head], head);
        //printf("TAIL2 ---> %c === %d\n", fullString[tail], tail);
        //printf("SUBS2 ---> %s\n", substring);
        //printf("----------------------------------------\n\n");
        q++; //constant time
    }
    currentLengthOfSubstring = getCurrentLengthOfSubstring(substring); //O(N) --> can be made constant time
    longestSubstring = currentLengthOfSubstring > longestSubstring ? currentLengthOfSubstring : longestSubstring; //O(1)
    return longestSubstring;
}

void main()
{
    //char s[] = {'p','w','w','k','e','w','\0'};
    //char s[] = {'d', 'v', 'd', 'f', '\0'};
    char s[] = {'a', 'a', 'b', 'a', 'a', 'b', '!', 'b', 'b', '\0'};
    printf("largest = %d\n", lengthOfLongestSubstring(s));
}
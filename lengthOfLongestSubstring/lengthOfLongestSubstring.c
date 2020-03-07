#include <stdio.h>
#include <stdbool.h>

int lengthOfLongestSubstring(char* fullString)
{
    int head = 0, tail = 0, pos = 0, it = 0;
    int currentLength = 0;
    int longest = 0;
    bool present = false;
    while (fullString[head] != '\0')
    {
        pos = 0; present = false; //reset these guys on all iterations
        for (it = tail; it < head; it++)
        {
            if(fullString[it] == fullString[head]) //checking for repetition from tail to just before head
            {
                present = true;
                break;
            }
        }
        pos = it; //get the position of repeated character

        if (present)
        {
            longest = currentLength > longest ? currentLength : longest; //using current positions of head and tail, calculate length of substring
            tail = pos + 1; //move tail to position just after duplicate was found
        }
        head ++;
        currentLength = head - tail; //calculate current length at the end of each iteration
    }
    return  longest > currentLength ? longest : currentLength;
    
}

void main(int argc, char **argv)
{
    while (--argc > 0)
    {
        printf("%d", lengthOfLongestSubstring(*++argv));
    }
    //char s[] = {'p','w','w','k','e','w','\0'};
    //char s[] = {'d', 'v', 'd', 'f', '\0'};
    //char s[] = {'a', 'a', 'b', 'a', 'a', 'b', '!', 'b', 'b', '\0'};
    //char s[] = {'b', 'b', 'b', 'b', 'b'};
    //char s[] = {'b'};
    
}
#include <stdio.h>
#include <stdbool.h>

char * longestPalindrome(char * s)
{
    int head = 0, tail = 0, it_head = 0, it_tail = 0;
    bool isPalindrome = false;
    int headLocation_and_length[2] = {0};
    char* ret;

    while(s[tail] != '\0')
    {
        isPalindrome = false;
        for(head = tail; head != '\0'; head++)
        {
            it_head = head; it_tail = tail;
            if (s[head] == s[tail])
            {
                while(it_tail <= it_head)
                {
                    if(s[it_head] == s[it_tail])
                    {
                        isPalindrome = true;
                    }
                    else
                    {
                        isPalindrome = false;
                        break;
                    }
                    it_tail++; it_head--;
                }
            }
            if(isPalindrome && (tail - head + 1) > headLocation_and_length[1])
            {
                headLocation_and_length[0] = head;
                headLocation_and_length[1] = tail -head + 1;
            }
        }
        tail++;
    }
    
}


void main()
{
    char s[] = "anamalayalampoo";
    printf
}
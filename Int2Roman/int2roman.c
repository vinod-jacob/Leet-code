#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char * intToRoman(int num)
{
    bool skip1000 = false, skip100 = false, skip10 = false;;
    char* r = (char*)malloc(20 * sizeof(char));
    for (int i = 0; i< 20; i++)
    {
        r[i] = '\0';
    }

    while (num - 1000 >= 0)
    {
        char M = 'M';
        strncat(r, &M, 1);
        num -= 1000;
    }
    if (1000 - num <= 100)
    {
        char C = 'C';
        char M = 'M';
        strncat(r, &C, 1);
        strncat(r, &M, 1);
        num -= 900;
        skip1000 = true;
    }
    if((!skip1000) && (num - 500 >= 0))
    {
        char D = 'D';
        strncat(r, &D, 1);
        num -= 500;
    }
    else if ((!skip1000) && (500 - num <= 100))
    {
        char C = 'C';
        char D = 'D';
        strncat(r, &C, 1);
        strncat(r, &D, 1);
        num -= 400;
    }
    while ((!skip1000) && (num - 100 >= 0))
    {
        char C = 'C';
        strncat(r, &C, 1);
        num -= 100;
    }
    if (100 - num <=10)
    {
        char X = 'X';
        char C = 'C';
        strncat(r, &X, 1);
        strncat(r, &C, 1);
        num -= 90;
        skip100 = true;
    }
    if ((!skip100) && (num - 50 >= 0))
    {
        char L = 'L';
        strncat(r, &L, 1);
        num -= 50;
    }
    else if ((!skip100) && (50 - num <= 10))
    {
        char X = 'X';
        char L = 'L';
        strncat(r, &X, 1);
        strncat(r, &L, 1);
        num -= 40;
    }
    while ((!skip100) && (num - 10 >= 0))
    {
        char X = 'X';
        strncat(r, &X, 1);
        num -= 10;
    }
    if (10 - num == 1)
    {
        char I = 'I';
        char X = 'X';
        strncat (r, &I, 1);
        strncat(r, &X, 1);
        num -= 9;
    }
    if (num - 5 >= 0)
    {
        char V = 'V';
        strncat(r, &V, 1);
        num -= 5;
    }
    else if (5 - num == 1)
    {
        char I = 'I';
        char V = 'V';

        strncat(r, &I, 1);
        strncat(r, &V, 1);
        num -= 4;
    }
    while (num -1 >= 0)
    {
        char I = 'I';
        strncat(r, &I, 1);
        num -= 1;
    }
    return r;
}


void main()
{
    printf("%s\n", intToRoman(1994));
}
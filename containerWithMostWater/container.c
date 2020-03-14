#include<stdio.h>
#include <stdbool.h>

int maxArea(int *height, int heightsize)
{
    int smaller = 0, currArea = 0, maxArea = 0;
    for (int i = 0; i <= heightsize-2; i++)
        for (int j = i+1; j <= heightsize-1; j++)
        {
            smaller = height[i] < height[j] ? i : j;
            currArea = (j-i) * height[smaller];
            maxArea = currArea > maxArea ? currArea : maxArea;
        }
    return maxArea;
}


void main()
{
    int h[] = {1,8,6,2,5,4,8,3,7}, hs = 9;
    printf("%d\n", maxArea(h, hs)); 
}
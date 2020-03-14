#include<stdio.h>
#include <stdbool.h>

int maxArea(int *height, int heightsize)
{

    int l = 0 , r = heightsize-1;
    int maxAr = height[l] >= height[r] ? height[r] * (r-l) : height[l] * (r-l);
    int currArea = 0;
    while ((r-l) > 0)
    {
        int ls = l, rs = r; //save the starting values of l and r. If neither have changed in a particular iteration, time to break
        int i = l, j = r;
        int d = r - l;
        int hl = height[l], hr = height[r];

        if (hl <= hr)
        { 
            while (((i+1) < r) && (height[i+1] <= (hl * d)/(r - (i+1))))
            {
                i++; 
            }
            if (i+1 < r)
            {
                l = i+1;
                currArea = height[l] >= height[r] ? height[r] * (r-l) : height[l] * (r-l);
            }
            else
                break;
        }
        else if (hr <= hl)
        {
            while (((j-1) > l) && (height[j-1] <= ((hr * d)/((j - 1) - l))))
            {
                j--;
            }
            if (j-1 > l)
            {
                r = j-1;
                currArea = height[l] >= height[r] ? height[r] * (r-l) : height[l] * (r-l);
            }
            else
                break;
        }
        if ((rs == r) && (ls == l)) //nothing moved. deadlock
            break;
        else
            maxAr = currArea > maxAr? currArea : maxAr;
    }
    return maxAr;
}

void main()
{
    int h[] = {8,10,14,0,13,10,9,9,11,11}, hs = 10;
    // int h[] = {1, 200, 1}, hs = 3;
    // int h[] = {2,3,4,5,18,17,6}, hs = 7;
    printf("%d\n", maxArea(h, hs)); 
}
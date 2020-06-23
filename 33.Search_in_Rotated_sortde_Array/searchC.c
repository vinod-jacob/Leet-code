#include <stdio.h>

int search(int* nums, int numsSize, int target)
{
    int L = 0; int R = numsSize -1;
    if (numsSize == 0) return -1;

    while (L <= R)
    {
        if (nums[L] == target)
            return L;
        if (nums[R] == target)
            return R;
        int m = (L+R)/2;
        if (nums[m] == target)
            return m;
        
        if (nums[L] <= nums[m]) //ascending
        {
            if (nums[L] < target && target < nums[m])
            {
                R = m -1;
            }
            else
            {
                L = m + 1;
            }
        }
        else
        {
            if(target > nums[L] || target < nums[m])
            {
                R = m - 1;
            }
            else
            {
                L = m + 1;
            }
        }
    }
    return -1;
}
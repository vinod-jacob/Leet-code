#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height)
    {
        if (height.empty())
            return 0;
        // logic:
        // 1. water is stored between the 2 highest bars. So find the first highest bar, and then proceed to find the next
        // highest bar. Water will eventually settle between these two. Onec these bars are gound, the level of water will
        // be only as tall as the shorter bar. Therefore, MAX amount of water will be (distance b/w the 2 bars) * (height of shorter bar)
        // The level of water will be less as there are bars of varying length in between. Therefore substract those from the MAX amount.
        // Once a higher bar is found, we can forget about all the bars behind it
        int h = 0;
        int sum = 0;
        for (int i = 1; i < height.size(); i++)
        {
            if (height[i] >= height[h])
            {
                int j = i-1;
                int max = (j-h) * height[h];
                while(j != h)
                {
                    max = max - height[j];
                    j--;
                }
                h = i;
                sum = sum + max;
            }
        }
        // suppose by the end of the array, we don't find a bar thats higher than the current highest. In this case, there will be a few more bars
        // that can hold water. We need to work our way backwards from them.
        // logic:
        // if height of last bar is less than height of (last - 1)th bar, forget about it.
        // else, theres defo going to be water stored there (because, water is going to collect between the highest and our current bar atleast)

        if (h != (height.size() -1))
        {
            int r = height.size() -1;
            int j = r-1;
            int tempsum =0;
            while(j != h)
            {
                if (height[r] <= height[j])
                {
                    r =j;
                }
                else
                {
                    tempsum = tempsum + (height[r] - height[j]);
                }
                j--;
            }
            sum += tempsum;
        }
        return sum;
    }
};

int main()
{
    vector<int> height = {1,3,0,1,5,4,3,1,0,2,0,1,5,0,4,3,1,6,5,0,2};
    Solution S1;
    cout << S1.trap(height) << endl;
}
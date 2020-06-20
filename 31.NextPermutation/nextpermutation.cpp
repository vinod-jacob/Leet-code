#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int len = nums.size() -1;
        int lim = -1;
        int swapper = 0;
        for(int i = len; i > lim; i--)
        {
            for(int j = i-1; j > lim; j--)
            {
                if(nums[i] > nums[j])
                {
                    swapper = i;
                    lim = j;
                    break;             
                }
            }
        }
        if (lim != -1)
        {
            int temp = nums[swapper];
            nums[swapper] = nums[lim];
            nums[lim] = temp;
        }
        sort(nums.begin() + (lim + 1), nums.end());
    }
};

int main()
{
    vector<int> nums = {4,2,0,4,7,7,8,7,5,2,0};
    // vector<int> nums = {3,2,1};
    for (auto it = nums.begin(); it != nums.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    Solution S1;
    S1.nextPermutation(nums);
    for (auto it = nums.begin(); it != nums.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int retsum = nums[0];
        int prevsum = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            prevsum = max(prevsum + nums[i], nums[i]);
            retsum = max(retsum, prevsum);
        }
        return retsum;
    }
};

int main()
{
    // vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums = {8,-19,5,-4,20};
    // vector<int> nums = {-2,-1};
    Solution S1;
    cout << S1.maxSubArray(nums);
}
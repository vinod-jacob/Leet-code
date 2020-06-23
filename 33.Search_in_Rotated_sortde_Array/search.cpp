#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int L = 0, R = nums.size()-1;
        int ret = -1;
        if (nums.empty())
            return ret;
        while (L<=R)
        {
            if (nums[L] == target)
            {
                ret = L;
                break;
            }
            else if(nums[R] == target)
            {
                ret = R;
                break;
            }

            int m = (L + R) /2;
            if (target == nums[m])
            {
                ret = m;
                break;
            }
            if (nums[L] <= nums[m]) //ascending set
            {
                if (nums[L] < target && target < nums[m]) //YES this is the range
                {
                    R = m - 1;
                }
                else
                {
                    L = m + 1;
                }
            }
            else
            {
                if(nums[L] < target || target < nums[m]) //YES this is the range
                {
                    R = m -1;
                }
                else
                {
                    L = m + 1;
                }
            }
        }
        return ret;
    }
};


int main()
{
    vector<int> nums = {14,15,3,4,6,7,9,11,12,13};
    int target = 9;
    Solution S1;
    cout << "found at pos = " << S1.search(nums, target) <<endl;
}
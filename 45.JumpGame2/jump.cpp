#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums)
    {
        int count = 0;
        int size = nums.size();
        if (size == 0 || size == 1) return 0;

        int tojump = 1;
        for(int index = 0; index < size-1; index = index + tojump)
        {
            int maxjump = 2;
            for(int jumplen = 1; jumplen <= nums[index]; jumplen++)
            {
                if (jumplen + index == size-1)
                {
                    tojump = jumplen;
                    break;
                }
                else
                {
                    if ((jumplen + index < size) && (jumplen + nums[jumplen + index] >= maxjump))
                    {
                        tojump = jumplen;
                        maxjump = jumplen + nums[jumplen + index];
                    }
                }
            }
            count++;
        }
        return count;
    }
};

int main()
{
    vector<int> nums = {2,1,1,1,1};
    Solution S1;
    cout << S1.jump(nums) << endl;
}
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int size = nums.size();
        if (size == 0 || size == 1)
            return true;
        return canjump(size-1, nums);
    }

    bool canjump(int index, vector<int>& nums)
    {
        if(index == 0)
        {
            return true;
        }
        else
        {
            for(int bj = 1; index - bj >=0; bj++)
            {
                if(nums[index-bj] >= bj)
                {
                    if(!canjump(index-bj, nums))
                        return false;
                    else
                        return true;
                }
            }
            return false;
        }
    }
};

int main()
{
    vector<int> nums = {0,1,2};
    Solution S1;
    cout<<S1.canJump(nums) << endl;
}
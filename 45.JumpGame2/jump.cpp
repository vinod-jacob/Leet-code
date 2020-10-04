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

        jump(0, count, nums);
        return count;
    }

    void jump(int index, int& count, vector<int>& nums)
    {
        if(index != nums.size()-1)
        {
            /* At each location, we try to make a jump that will
            take us the most far, unless any jump will take us to the final destination itself*/

            int val = nums[index];
            int combinedmaxjump = 2; /*2 is the minimum length we can jump with 2 elements*/
            int tojump = 1;

            for(int jumplen = 1; jumplen <= val; jumplen++)
            {
                if(index + jumplen == nums.size() -1)
                {
                    tojump = jumplen;
                    break;
                }
                else
                {
                    if (jumplen + nums[index + jumplen] > combinedmaxjump)
                    {
                        combinedmaxjump = jumplen + nums[index + jumplen];
                        tojump = jumplen;
                    }
                }
            }
            count++;
            Solution::jump(index+tojump, count, nums);
        }
    }
};

int main()
{
    vector<int> nums = {2,3,1,1,4};
    Solution S1;
    cout << S1.jump(nums) << endl;
}
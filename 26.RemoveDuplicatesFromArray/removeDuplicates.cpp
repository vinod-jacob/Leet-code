#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;

        int len = nums.size()-1;
        int i = 0, j  = 1;
        for (i= 0; i < len; i++)
        {
            while(nums[i] == nums[j])
            {
                if (j < len)
                    j++;
                else
                {
                    return i+1;
                }
            }
            nums[i+1] = nums[j];
        }
        return i+1;
    }
};

int main()
{
    vector<int> nums = {0,0,0,0,1,1,1,1,2,2,3,6,6};
    Solution S1;
    int len = S1.removeDuplicates(nums);
    for (int i = 0; i < len; i++)
        cout << nums[i];
    cout <<endl;
}
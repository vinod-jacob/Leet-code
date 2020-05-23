#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        if (nums.empty()) return 0;

        int i = nums.size() - 1;
        int j = i - 1;
        
        for(i; i >= 0;)
        {
            if (nums[i] == val)
            {
                i--; j--;
            }
            else if (j < 0)
            {
                break;
            }
            else if( j >= 0 && nums[j] == val)
            {
                nums[j] = nums[i];
                nums[i] = val;
            }
            else if (j < 0)
            {
                break;
            }
            else
            {
                j--;
            }
            
        }
        return i+1;
    }
};

int main()
{
    vector<int> nums = {0,2,3,4,1,1,2,2,2,4,5,2};
    // vector<int> nums = {3};
    int val = 2;
    Solution S1;
    int len = S1.removeElement(nums, val);
    for (int i = 0; i < len; i++)
        cout << nums[i];
    cout << endl;
    return 0;
}
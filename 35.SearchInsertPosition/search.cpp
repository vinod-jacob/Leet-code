#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        if (nums.empty()) return 0;

        int L = 0, R = nums.size()-1;
        while(L <= R)
        {
            int m = L + (R-L)/2;
            if (nums[m] == target)
            {
                return m;
            }
            else if (nums[m] < target)
            {
                L = m+1;
            }
            else if (nums[m] > target)
            {
                R = m-1;
            }
        }
        return (R+1);    
    }
};


int main()
{
    vector<int> nums = {1,3,5,6};
    int target = 6;
    Solution S1;
    cout << "position = " << S1.searchInsert(nums, target) << endl;
}
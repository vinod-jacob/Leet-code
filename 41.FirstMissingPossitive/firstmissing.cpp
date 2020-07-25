#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        for(int i = 0; i< nums.size(); i++)
        {
            // keep swapping till all the numbers that appear in this slot is placed in the correct slot. Stop // when this slot has the correct number or the number is unswappable. {3,4,-1,1} -> keep swapping coz inputs like these

            // don't swap if the number in the slot is greater than the number of slots

            // only swap the positive numbers.

            // a number becomes unswappable if
            // 1. the number in the slot is -ve
            // 2. the number is gretaer than the number of available slots
            // 3. the slot which is meant to contain this number already has this number
            // in any of the above cases, stop!
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] -1] != nums[i])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i]-1 != i)
                return i+1;
        }
        return nums.size() +1;
    }
};
int main()
{
    vector<int> nums = {3,4,-1,1};
    Solution S1;
    cout << S1.firstMissingPositive(nums) << endl;
}
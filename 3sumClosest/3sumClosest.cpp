#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int sum = 0;
        sort(nums.begin(), nums.end());
        int distance = INT32_MAX;

        for(int i = 0; i < nums.size()-1;)
        {
            int L = i+1;
            int R = nums.size()-1;
            
            while (L < R)
            {
                int temp_sum = nums[i] + nums[L] + nums[R];
                if (target == temp_sum)
                {
                    sum = temp_sum;
                    return sum;
                }
                else if(temp_sum < target)
                {
                    int x = abs(target - temp_sum);
                    if (x < distance)
                    {
                        distance = x;
                        sum = temp_sum;
                    }
                    int temp = nums[L];
                    while (L < R && nums[L] == temp)
                    {
                        L++;
                    }
                }
                else if(temp_sum > target)
                {
                    int x = abs(target - temp_sum);
                    if (x < distance)
                    {
                        distance = x;
                        sum = temp_sum;
                    }
                    int temp = nums[R];
                    while ( L < R && nums[R] == temp)
                    {
                        R--;
                    }
                }
            }//while end

            int temp = nums[i];
            while(i < nums.size() && temp == nums[i]) i++;
        }
        return sum;
    }
};


int main()
{
    vector<int> nums = {-1, 2, 1, -4};
    // vector<int> nums = {1,1,-1,-1,3};
    // vector<int> nums = {1,2,5,10,11};
    Solution S;
    cout << "closest = " << S.threeSumClosest(nums, 1) << endl;
}
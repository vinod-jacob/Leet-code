#include<iostream>
#include<vector>
#include<set>
// #include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        set<int> s;
        for(auto it = nums.begin(); it != nums.end(); it++)
        {
            s.insert(*it);
        }
        int i = 1;
        for(i ; i < INT32_MAX; i++)
        {
            if(s.find(i) == s.end())
                break;
        }
        return i;
    }
};

int main()
{
    vector<int> nums = {3,4,-1,1};
    Solution S1;
    cout << S1.firstMissingPositive(nums) << endl;
}
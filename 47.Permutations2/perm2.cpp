#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>> perms;
        vector<int> perm;
        sort(nums.begin(), nums.end());
        permute(perms, perm, nums);
        return perms;
    }

    void permute(vector<vector<int>>& perms, vector<int>& perm, vector<int> nums)
    {
        if (nums.empty())
        {
            perms.push_back(perm);
        }
        else
        {
            for(int i = 0; i < nums.size(); i++)
            {
                int j = nums[i];
                perm.push_back(j);
                nums.erase(nums.begin() + i);
                permute(perms, perm, nums);
                perm.pop_back();
                while(i < nums.size() && j == nums[i]) i++;
                nums.insert(nums.begin()+i, j); //put the number back in the right sport, to retain the sorted order
            }
        }

    }
};

int main()
{
    vector<int> nums = {1,1,2,3};
    Solution S1;
    vector<vector<int>> perms = S1.permuteUnique(nums);
    for (auto it = perms.begin(); it != perms.end(); it++)
    {
        for(auto jt = it->begin(); jt != it->end(); jt++)
        {
            cout << *jt << " ";
        }
        cout << endl;
    }
}
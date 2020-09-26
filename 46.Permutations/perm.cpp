#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> perms;
        vector<int> perm;
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
                nums.insert(nums.begin(), j);
            }
        }

    }
};

int main()
{
    vector<int> nums = {1,2,3};
    Solution S1;
    vector<vector<int>> perms = S1.permute(nums);
    for (auto it = perms.begin(); it != perms.end(); it++)
    {
        for(auto jt = it->begin(); jt != it->end(); jt++)
        {
            cout << *jt << " ";
        }
        cout << endl;
    }
}
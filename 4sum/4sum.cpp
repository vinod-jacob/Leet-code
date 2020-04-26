#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector <int>> res;
        if(nums.size() < 4) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; )
        {
            for(int j = i + 1; j < nums.size() - 2; )
            {
                int L = j + 1;
                int R = nums.size() - 1;
                int T = target - nums[i] -nums[j];
                while (L < R)
                {
                    int NR = nums[R]; int NL = nums[L];
                    if (NR + NL == T)
                    {
                        res.push_back({nums[i], nums[j], NL, NR});
                        int temp_l = NL;
                        int temp_r = NR;
                        while(L < R && temp_l == nums[L]) L++;
                        while(L < R && temp_r == nums[R]) R--;
                    }
                    else if (NR + NL < T)
                    {
                        int temp = NL;
                        while (L < R && temp == nums[L])
                        {
                            L++;
                        }
                    }
                    else if (NR + NL > T)
                    {
                        int temp = NR;
                        while(L < R && nums[R] == temp)
                        {
                            R --;
                        }
                    }
                }
                int temp = nums[j];
                while(j < nums.size() && temp == nums[j] ) j++;
            }
            int temp = nums[i];
            while(i < nums.size() && temp == nums[i]) i++;
        }
        return res;    
    }
};

int main()
{
    vector<int> nums = {-3,-2,-1,0,0,1,2,3};
    int target = 0;
    Solution S1;

    vector<vector <int>> ans = S1.fourSum(nums, target);

    for(auto i = ans.begin(); i != ans.end(); i++)
    {
        for (auto j = i->begin(); j != i->end(); j++)
        {
            cout << *j << "  ";
        }
        cout << endl;
    }
}
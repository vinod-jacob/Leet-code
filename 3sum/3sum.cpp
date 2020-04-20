#include <iostream>
#include <vector>
#include <set>
#include<algorithm>

using namespace std;

    class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums)
        {
            vector<vector<int>> res;
            sort(nums.begin(), nums.end());

            for (int i = 0; i < nums.size();)
            {
                int l = i+1;
                int u = nums.size() -1;
                int target = -nums[i];

                while(l<u)
                {
                    if (nums[l] + nums[u] == target)
                    {
                        res.push_back({nums[i], nums[l], nums[u]});
                        int temp_l = nums[l];
                        int temp_u = nums[u];
                        while(l < u&& nums[l] == temp_l) l++;
                        while(u > l && nums[u] == temp_u) u--;
                        
                    }
                    else if (nums[l] + nums[u] > target)
                    {
                        int temp_u = nums[u];
                        while( u > l && nums[u] == temp_u) u--;
                    }
                    else if(nums[l] + nums[u] < target)
                    {
                        int temp_l = nums[l];
                        while (l < u && nums[l] == temp_l) l++;
                    }
                }
                int temp_i = nums[i];
                while ( i < nums.size() && nums[i] == temp_i) i++;
            }
            return res;            
        }
    };

    int main()
    {
        // vector<int> a = {-1,0,1,2,-1,-4};
        vector<int> a = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
        Solution S;
        vector<vector<int>> result =  S.threeSum(a);
        for(auto i = result.begin(); i != result.end(); i++)
        {
            for (auto j = i->begin(); j != i->end(); j++)
            {
                cout << *j << " ";
            }
            cout << endl;
        }
    }

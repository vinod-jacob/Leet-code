#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

    class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums)
        {
            vector<vector<int>> sum3;
            multimap<int, int> umap;
            for (int i = 0; i < nums.size(); i++)
            {
                for (auto j = umap.begin(); j != umap.end(); j++)
                {
                    vector<int> triplet;
                    int target = - (j->first + nums[i]);
                    multimap<int, int>::iterator found = umap.find(target);
                    if(found != umap.end())
                    {
                        if (j->second != found->second) //make sure you don't find yourself,babe
                        {
                            triplet.push_back(nums[i]);
                            triplet.push_back(j->first);
                            triplet.push_back(target);
                            sort(triplet.begin(), triplet.end());
                            bool dup = false;
                            for (auto k = sum3.begin(); k != sum3.end(); k++)
                            {
                                if (*k == triplet)
                                {
                                    dup = true;
                                    break;
                                }
                            }
                            if(!dup)
                            {
                                sum3.push_back(triplet);
                            }
                        }
                        
                    }
                }
                pair<int,int> numAndInd;
                numAndInd.first = nums[i]; numAndInd.second = i;
                umap.insert(numAndInd);
            }
            return sum3;
        }
    };

    int main()
    {
        //vector<int> a = {-1, 0, 1, 2, -1, -4, 44, 0, -44, 1, 0};
        vector<int> a = {0,0,0};
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

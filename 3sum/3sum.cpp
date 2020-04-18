#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include<algorithm>

using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums)
        {
            vector<vector<int>> sum3;
            unordered_multimap<int, int> umap;
            unordered_multimap<int, int> umap_copy;
            for (int i = 0; i < nums.size(); i++)
            {
                unordered_multimap<int, int> umap_copy = umap;
                for (auto j = umap_copy.begin(); j != umap_copy.end(); j++)
                {
                    vector<int> triplet;

                    int target = - (j->first + nums[i]);
                    unordered_multimap<int, int>::iterator found = umap_copy.find(target);
                    if(found != umap_copy.end())
                    {
                        if (j->second != found->second) //make sure you don't find yourself,babe
                        {
                            triplet.push_back(nums[i]);
                            triplet.push_back(j->first);
                            triplet.push_back(target);
                            umap_copy.erase(found);
                            // sum3.push_back(triplet);
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
                umap.insert({nums[i], i});
            }
            return sum3;
        }
    };

    int main()
    {
        vector<int> a = {-1, 0, 1, 2, -1, -4, 44, 0, -44, 1, 0};
        // vector<int> a = {0,0,0};
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

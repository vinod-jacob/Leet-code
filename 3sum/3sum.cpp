#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

    class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums)
        {
            vector<vector<int>> sum3;
            vector<int>::iterator i, j, k;
            for (i = nums.begin(); i != nums.end(); i++)
            {
                for (j = i + 1; j != nums.end(); j++)
                {
                    for(k = j + 1; k != nums.end(); k++)
                    {
                        if ((*i+ *j + *k) == 0)
                        {   
                            vector<int> triplets;
                            triplets.push_back(*i);
                            triplets.push_back(*j);
                            triplets.push_back(*k);
                            sort(triplets.begin(), triplets.end());
                            bool f = false;
                            for(auto q = sum3.begin(); q != sum3.end(); q++)
                            {                               
                                if (*q == triplets)
                                {
                                    f = true;
                                    break;
                                }
                            }
                            if (!f)
                            {
                                sum3.push_back(triplets);
                            }
                            
                        }
                    }
                }
            }
            return sum3;
        }
    };

    int main()
    {
        vector<int> a = {-1, 0, 1, 2, -1, -4, 44, 0, -44, 1};
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

#include <iostream>
#include <vector>
#include<algorithm>
#include<set>


using namespace std;

class Solution {
private:
vector<int> cands;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<int> sums;
        set<vector<int>> res_set;
        cands =  candidates;
        getcombsum(res_set, sums, target);
        vector<vector<int>> res(res_set.begin(), res_set.end());
        return res;
    }

    void getcombsum(set<vector<int>>& res, vector<int> sums, int target)
    {
        if (target == 0)
        {
            sort(sums.begin(), sums.end());
            if(res.find(sums) == res.end())
                res.insert(sums);
        }
        else if(target > 0)
        {
            for(auto it = cands.begin(); it != cands.end(); it++)
            {
                if (*it <= target)
                {
                    vector<int> temp = sums;
                    temp.push_back(*it);
                    getcombsum(res, temp, target-*it);
                }
            }
        }

    }
};

int main()
{
    Solution S1;
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> res = S1.combinationSum(candidates, target);
    cout << endl;
    for (auto it = res.begin(); it != res.end(); it++)
    {
        for(auto jt = it->begin(); jt != it->end(); jt++)
        {
            cout << *jt << " ";
        }
        cout << endl;
    }
}
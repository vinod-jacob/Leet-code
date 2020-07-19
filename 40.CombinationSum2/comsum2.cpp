#include <iostream>
#include <vector>
#include <set>
#include<algorithm>


using namespace std;

class Solution {
private:
set<vector<int>> res;
vector<int> sums;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        getcombsum(candidates, target, 0);
        vector<vector<int>> output;
        for(auto it = res.begin(); it !=res.end(); it++)
        {
            output.push_back(vector<int> (it->begin(), it->end()));
        }
        return output;
    }

    void getcombsum(vector<int>& candidates, int target, int idx)
    {
        if(target == 0)
        {
            res.insert(sums);
        }
        else
        {
            for(int i = idx; i < candidates.size(); i++)
            {
                if (candidates[idx] > target)
                    break;
                sums.push_back(candidates[i]);
                getcombsum(candidates, target - candidates[i], i+1);
                sums.pop_back();
            }
        }
    }
};

int main()
{
    Solution S1;
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> res = S1.combinationSum(candidates, target);
    for (auto it = res.begin(); it != res.end(); it++)
    {
        for(auto jt = it->begin(); jt != it->end(); jt++)
        {
            cout << *jt << " ";
        }
        cout << endl;
    }
}
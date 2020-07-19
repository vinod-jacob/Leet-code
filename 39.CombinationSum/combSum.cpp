#include <iostream>
#include <vector>
#include<algorithm>


using namespace std;

class Solution {
private:
vector<vector<int>> res;
vector<int> sums;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        getcombsum(candidates, target, 0);
        return res;
    }

    void getcombsum(vector<int>& candidates, int target, int idx)
    {
        if(target == 0)
        {
            res.push_back(sums);
        }
        else
        {
            for(int i = idx; i < candidates.size(); i++)
            {
                if (candidates[idx] > target)
                    break;
                sums.push_back(candidates[i]);
                getcombsum(candidates, target - candidates[i], i);
                sums.pop_back();
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
    for (auto it = res.begin(); it != res.end(); it++)
    {
        for(auto jt = it->begin(); jt != it->end(); jt++)
        {
            cout << *jt << " ";
        }
        cout << endl;
    }
}
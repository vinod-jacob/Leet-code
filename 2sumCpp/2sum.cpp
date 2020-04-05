#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        pair<int, int> numberAndIndex;
        vector<int> ret;
        unordered_map<int, int>::iterator it;
        int input_length = nums.size();
        for(int i = 0; i < input_length; i++)
        {
            numberAndIndex.first = nums[i]; numberAndIndex.second = i;
            if(hashmap.find(target-nums[i]) != hashmap.end())
            {
                ret.push_back(hashmap[target-nums[i]]);
                ret.push_back(i);
                break;
            }
            else
            {
                hashmap.insert(numberAndIndex);
            }
        }
        return ret;
    }
};

int main()
{
    Solution S;
    vector<int> num = {2,7,10,24,33,44,22,5};
    int target = 9;
    vector<int> ret = S.twoSum(num, target);
    for (auto i = ret.begin(); i != ret.end(); i++)
    {
        cout << *i << " ";
    }
}


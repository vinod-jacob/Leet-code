#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        map<string, vector<string>> hashmap;

        for(auto it = strs.begin(); it != strs.end(); it++)
        {
            string temp = *it;
            sort(temp.begin(), temp.end());

            if (hashmap.find(temp) != hashmap.end())
            {
                hashmap[temp].push_back(*it);
            }
            else
            {
                vector<string> sv;
                sv.push_back(*it);
                hashmap[temp] = sv;
            }

        }

        vector<vector<string>> res;
        for(auto it = hashmap.begin(); it != hashmap.end(); it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};

int main()
{
    vector<string> sv = {"cab", "tin", "pew", "duh", "may", "buy", "doc", "ill", "bar", "max"};
    Solution S1;
    S1.groupAnagrams(sv);
}
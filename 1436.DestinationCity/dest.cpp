#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution
{
public:
    string destCity(vector<vector<string>>& paths)
    {
        string searchCity = paths[0][0];
        map<string, string> atlas;
        for(int i = 0; i < paths.size(); i++)
        {
            atlas[paths[i][0]] = paths[i][1];
            while(atlas.find(searchCity) != atlas.end())
            {
                searchCity = atlas[searchCity];
            }
        }
        return searchCity;
    }
};


int main()
{
    vector<vector<string>> cities = {{"A", "B"}, {"B", "C"}, {"C", "D"}};
    Solution S1;
    cout << S1.destCity(cities);
}
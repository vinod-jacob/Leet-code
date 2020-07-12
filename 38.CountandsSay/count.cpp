#include<iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        vector<char> d = getnum(n);
        string ret;
        for(auto it = d.rbegin(); it != d.rend(); it++)
        {
            ret = ret + *it;
        }
        return ret;
    }

    vector<char> getnum(int n)
    {
        if (n == 2)
        {
            vector<char> ret;
            ret.push_back('1');
            ret.push_back('1');
            return ret;
        }
        else
        {
            vector<char> prev = getnum(n-1);
            vector<char> ret;
            for(auto it = prev.begin(); it != prev.end();)
            {
                char d = *it;
                int count = 0;
                while(it != prev.end() && *it == d)
                {
                    count++;
                    it++;
                }
                ret.push_back(d);
                ret.push_back(count + '0');
            }
            return ret;
        }
    }
};

int main()
{
    Solution S1;
    cout << S1.countAndSay(5) << endl;
}
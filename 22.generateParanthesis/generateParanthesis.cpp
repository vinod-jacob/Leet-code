#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        if (n == 0)
            return vector<string>();
        int N = 2*n;
        string prefix = "";
        vector<string> allPermuts;
        genAllPar(prefix, N, 0, allPermuts);
        return allPermuts;

    }

    void genAllPar(string prefix, int n, int score, vector<string> &allPermuts)
    {
        if(n != 0)
        {
            genAllPar(prefix +'(', n-1, score +1, allPermuts);
            if (score - 1 >= 0) genAllPar(prefix + ')', n-1 ,score -1, allPermuts);
        }
        else if(n == 0 && score == 0)
        {
            allPermuts.push_back(prefix);
        }
    }
};

int main()
{
    Solution s1;
    vector<string> ans;
    ans = s1.generateParenthesis(4);

    for (auto i = ans.begin(); i != ans.end(); i++)
    {
        cout << *i <<endl;
    }
}
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
    const char* brackets = "()";
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
            for(int i = 0; i < 2; i++)
            {
                char ch = brackets[i];
                int tracker = score;
                ch == '('? tracker++ : tracker--;
                if (tracker < 0) break;
                genAllPar(prefix + ch, n-1, tracker, allPermuts);
            }
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
    ans = s1.generateParenthesis(12);

    for (auto i = ans.begin(); i != ans.end(); i++)
    {
        cout << *i <<endl;
    }
}
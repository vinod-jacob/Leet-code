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
        genAllPar(prefix, N, allPermuts);
        return filterValid(allPermuts);
    }

    void genAllPar(string prefix, int n,  vector<string> &allPermuts)
    {
        if(n != 0)
        {
            for(int i = 0; i < 2; i++)
            {
                char ch = brackets[i];
                genAllPar(prefix + ch, n-1, allPermuts);
            }
        }
        else if(n == 0)
        {
            allPermuts.push_back(prefix);
        }
    }

    vector<string> filterValid(vector<string> &allPermuts)
    {
        vector<string> ans;
        for(auto i = allPermuts.begin(); i != allPermuts.end(); i++)
        {   
            string eachPermut = *i;
            bool valid = true;
            stack<char> s;
            for(int j = 0; j < eachPermut.size(); j++)
            {
                char ch = eachPermut[j];
                if (ch == '(')
                {
                    s.push(ch);
                }
                else if (!s.empty())
                {
                    s.pop();
                }
                else if(s.empty())
                {
                    valid = false;
                    break;
                }
            }
            if (valid && s.empty())
            {
                ans.push_back(*i);
            }
        }
        return ans;
    } 
};

int main()
{
    Solution s1;
    vector<string> ans;
    ans = s1.generateParenthesis(0);

    for (auto i = ans.begin(); i != ans.end(); i++)
    {
        cout << *i <<endl;
    }
}
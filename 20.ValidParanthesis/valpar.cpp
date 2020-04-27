#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        stack<char> st;
        for(int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else 
            {
                if(!st.empty()) //this check is needed coz top() on empty stack seg faults
                {
                    char ch = st.top();
                    if((ch == '(' && s[i] == ')') ||(ch == '{' && s[i] == '}') || (ch == '[' && s[i] == ']'))
                        st.pop();
                    else
                        return false;
                }
                else
                    return false;
            }
        }
        if(!st.empty())
            return false;
        return true;
    }
};

int main()
{
    string s = "())";
    Solution S1;
    cout << S1.isValid(s) << endl;
}
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;
/*
Dynamic Programming approach:
1. A valid set can only end with )
2. A valid set can end with either () or ))
3. If the set ends with (), it means that it is a valid set for itself. Therefore, the total length
of the valid set will be 2 + length of (i-2)th entry
4. If the set ends with )), that means
    a. if the (i-1)th bracket closed a valid set, then there must be a '(' before the valid set started. If yes, then add 2 to the length of the
    (i-1)th valid set
    b. if this ith bracket is did indeed form a valid set, it needs to be clubbed with
    the previous valid sets, if it exists
*/
class Solution{
public:
    int longestValidParentheses(string s)
    {
        int longest = 0;
        vector<int> memo(s.size(), 0);
        for(int i = 0; i < s.size() ; i++)
        {
            if (s[i] == ')' && (i-1) >= 0 && s[i-1] == '(')
            {
                memo[i] = memo[i-2] + 2; //memo[i-2] already has a value equal to the sum total of all previous valid sets
            }
            else if (s[i] == ')' &&  (i-1) >= 0 && s[i-1] == ')')
            {
                if ((i - memo[i-1] - 1) >= 0 && s[i - memo[i-1] - 1] == '(')
                {
                    memo[i] = memo[i-1] +2;
                    if(i - memo[i-1] -2 >= 0)
                        memo[i] += memo[i - memo[i-1] -2]; //club with previous valid sets
                }
            }
            longest = memo[i] > longest ? memo[i] : longest;
        }
        return longest;
    }
};

int main()
{
    string s = "()";
    Solution S1;
    cout << S1.longestValidParentheses(s) << endl;
}


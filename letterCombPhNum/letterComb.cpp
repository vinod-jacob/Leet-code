#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
    map <char, string> tel = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, \
        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        string prefix = "";
        recurse(prefix, digits, res);
        return res;
    }

    void recurse(string prefix, string digits, vector<string> &res)
    {
        if (digits.size() != 0)
        {
            char d = digits[0];
            string decremented_digits = digits.substr(1, digits.size()-1);
            string letters = tel[d];
            for (int i = 0; i<letters.size(); i++)
            {
                recurse(prefix + letters[i], decremented_digits, res);
            }
        }
        else if (prefix != "")
        {
            res.push_back(prefix);
        }
    }
};

int main()
{
    Solution S1;
    vector<string> ans = S1.letterCombinations("23");
    for (auto i = ans.begin(); i != ans.end(); i++)
    {
        cout << *i << "\n";
    }
}
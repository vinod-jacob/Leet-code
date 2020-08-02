#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2)
    {
        if(num1 == "0" || num2 == "0")
            return "0";
        vector<char> n1, n2;
        for(auto it = num1.begin(); it != num1.end(); it++)
        {
            n1.push_back(*it - '0');
        }
        for(auto it = num2.begin(); it != num2.end(); it++)
        {
            n2.push_back(*it - '0');
        }

        vector<vector<int>> metadata;
        int count = 0;
        for(auto it = n2.rbegin(); it != n2.rend(); it++)
        {
            vector<int> temp;
            for(int i = 0; i < count; i++)
            {
                temp.push_back(0);
            }

            count ++;
            int carry = 0;
            for(auto jt = n1.rbegin(); jt != n1.rend(); jt++)
            {
                int prod = carry + (*jt * *it);
                carry = prod/10;
                temp.push_back(prod%10);
            }
            if (carry != 0)
                temp.push_back(carry);

            metadata.push_back(temp);
        }

        int sizemax = metadata[metadata.size() - 1].size();
        vector<int> result;
        int carry = 0;

        for(int i = 0; i < sizemax; i++)
        {
            int tempsum = carry;
            for(int j = 0; j < metadata.size(); j++)
            {
                if (i < metadata[j].size())
                {
                    tempsum = metadata[j][i] + tempsum;
                }

            }
            result.push_back(tempsum%10);
            carry = tempsum/10;
        }
        while(carry > 0)
        {
            result.push_back(carry%10);
            carry = carry/10;
        }

        string res;
        for(auto it = result.rbegin(); it != result.rend(); it++)
        {
            res.append(1u, *it+'0');
        }
        return res;
    };
};

int main()
{
    string s1 = "12536";
    string s2 = "0";
    Solution S1;
    cout << S1.multiply(s1, s2) << endl;

}
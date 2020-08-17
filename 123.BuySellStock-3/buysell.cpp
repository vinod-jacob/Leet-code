#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
private:
    vector<int> p;
public:
    int maxProfit(vector<int>& prices)
    {
        if(prices.size() == 0 || prices.size() == 1)
            return 0;

        deque<int> d = {-1,1,-1,1};
        queue<int> q(d);
        p = prices;
        int max = 0;
        dfs(0, q,0, max);
        return max;
    }

    void dfs(int i, queue<int> q, int sum, int& max)
    {
        if(i == p.size() || q.empty())
        {
            max = sum > max ? sum : max;
        }
        else
        {
            dfs(i+1, q, sum, max);

            int m = q.front();
            q.pop();
            sum  = sum + (p[i] * m);
            if (m == -1 || (m == 1 && sum > 0))
                dfs(i+1, q, sum, max);

        }

    }
};

int main()
{
    vector<int> p = {3,3,5,0,0,3,1,4};
    // vector<int> p = {1,2,3,4,5};
    // vector<int> p = {7,6,5,4,3,2};
    Solution S1;
    cout << S1.maxProfit(p) << endl;
}
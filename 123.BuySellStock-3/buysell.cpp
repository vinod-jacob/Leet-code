#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
private:
    vector<int> p;
public:
    /* int maxProfit(vector<int>& prices)
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

    } */

    int maxProfit(vector<int>& prices)
    {
        if(prices.size() == 0 || prices.size() == 1)
            return 0;

        int profit = 0;
        int M = 0;
        int z = profit - prices[0];
        int zmax = z;
        int mins = prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            M = max(M, prices[i] + zmax);
            mins = min (mins, prices[i]);
            profit = max(profit, prices[i] - mins);
            z = profit - prices[i];
            zmax = max(z, zmax);
        }
        return M;
    }
};

int main()
{
    vector<int> p = {3,3,5,0,0,3,1,4};
    // vector<int> p = {3,3,5,0,0,3,1,4};
    // vector<int> p = {3,3,5,0,0,3,1,4};
    // vector<int> p = {5, 11, 3, 50, 60, 90};
    Solution S1;
    cout << S1.maxProfit(p) << endl;
}
#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    int divide(int dd, int ds) 
    {
        if (ds == INT32_MIN)
        {
            if(dd == INT32_MIN) return 1;
            else return 0;
        }
        else if (dd == 0) return 0;

        if (dd == INT32_MIN && ds == -1) // this will overflow, therfore return INT32_MAX as per problem description
            return INT32_MAX;

        int Q = 0;
        bool isneg = false;
        stack<int> table; 
        stack<int> Xds; 

        if (dd < 0 && ds > 0 || dd > 0 && ds < 0) // we need to get the negative of ds first. This won't overflow coz we've handled that above
        {
            ds = -ds;
            isneg = true;
        }
        if ((dd < 0 && ds < 0 && ds < dd) || (dd > 0 && ds > 0 && ds > dd )) return 0;

        if (dd > 0) 
        {
            // create table where ds goes till just below dd (simultaneously ensuring that each time we double. the sum stays below INT32_MAX)
            int mult = ds; int times = isneg? -1:1;
            while(mult <= dd)
            {
                table.push(mult); /* cout << mult << " "; */
                Xds.push(times); /* cout << times << endl; */
                if (INT32_MAX - mult >= mult)
                {
                    mult += mult;
                    times += times;
                }
                else break;

            }

            while(dd > 0 && !table.empty())
            {
                if (table.top() <= dd)
                {
                    int top = table.top();
                    dd = dd - top;
                    Q = Q + Xds.top();
                    table.pop();
                    Xds.pop();
                }
                else
                {
                    table.pop();
                    Xds.pop();
                }
            }
        }
        else 
        {
            // create table where ds goes till just greater that dd( simultaneosly ensureing that each time we double, the sum stays graeter that INT32_MIN)
            int mult = ds; int times = isneg? -1:1;
            while(dd <= mult)
            {
                table.push(mult);
                Xds.push(times);
                if (INT32_MIN - mult <= mult)
                {
                    mult += mult;
                    times += times;
                }
                else break;

            }

            while(dd < 0 && !table.empty())
            {
                if (table.top() >= dd)
                {
                    int top = table.top();
                    dd = dd - top;
                    Q = Q + Xds.top();
                    table.pop();
                    Xds.pop();
                }
                else
                {
                    table.pop();
                    Xds.pop();
                }
            }
        }
        return Q;
    }
};

int main(int argc, char *argv[])
{
    Solution S1;
    if (argc != 3)
    {
        cout << "number of args error: " << endl;
    }
    else
    {
        Solution S1;
        cout << S1.divide(atoi(argv[1]) , atoi(argv[2]) ) << endl;
    }
    
}
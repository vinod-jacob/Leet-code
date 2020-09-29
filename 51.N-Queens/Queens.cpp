#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:

    bool checkvertical(int c, int r, vector<string> cb)
    {
        int n = cb.size();
        for(int i = r-1; i >= 0; i--)
        {
            if(cb[i][c] != '.')
                return false;
        }
        return true;
    }

    bool checkdiag(int r, int c, vector<string> cb)
    {
        int n = cb.size();
        {
            for(int i = 1; r-i >=0; i++ )
            {
                if (((c+i < n) && (cb[r-i][c+i] != '.')) || ((c-i >= 0 ) && cb[r-i][c-i] != '.'))
                    return false;
            }

            for(int i = 1; r+i < n; i++)
            {
                if(((c+i < n) && (cb[r+i][c+i] != '.')) || ((c-i >= 0 ) && cb[r+i][c-i] != '.'))
                    return false;
            }
            return true;
        }
    }

    bool isQueenSafe(int r, int c , vector<string> cb)
    {

        if (checkdiag(r,c,cb) && checkvertical(c, r, cb))
            return true;
        return false;
    }

    void insertQueen(int r, int c, vector<string>& cb, int& queens)
    {
        cb[r][c] = 'Q';
        queens--;
    }

    void removeQueen(int r, int c, vector<string>& cb, int& queens)
    {
        cb[r][c] = '.';
        queens++;
    }

public:

    vector<vector<string>> solveNQueens(int n)
    {
        int Queens = n;
        vector<string> cb(n,string(n,'.'));

        vector<vector<string>> result;
        solve(result, cb, -1, 0, Queens);
        return result;
    }

    bool solve(vector<vector<string>>& result, vector<string> cb, int row, int column, int queens)
    {
        int n = cb.size();
        if(!isQueenSafe(row, column, cb))
            return false;
        else if(queens == 0)
        {
            result.push_back(cb);
            return true;
        }
        else
        {
            row++;
            for(int j = 0; j < n; j++)
            {
                insertQueen(row, j, cb, queens);
                if (!solve(result, cb, row, j, queens))
                    removeQueen(row, j, cb, queens);
                else
                    break;
            }
            return false;
        }
    }
};


int main()
{
    Solution S1;
    vector<vector<string>> res = S1.solveNQueens(8);

    for(auto it = res.begin(); it != res.end(); it++)
    {
        for(auto jt = it->begin(); jt != it->end(); jt ++)
        {
            cout << *jt << endl;
        }
        cout << endl;
    }
}

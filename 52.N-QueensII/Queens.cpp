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

    int totalNQueens(int n)
    {
        int Queens = n;
        vector<string> cb(n,string(n,'.'));

        int result = 0;
        solve(result, cb, -1, 0, Queens);
        return result;
    }

    bool solve(int& result, vector<string> cb, int row, int column, int queens)
    {
        int n = cb.size();
        if(!isQueenSafe(row, column, cb))
            return false;
        else if(queens == 0)
        {
            result++;
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
    int res = S1.totalNQueens(8);

    cout << res;
}

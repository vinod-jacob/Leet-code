#include<iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        set<int> columns[9];
        set<int> threebythree[3];
        for(int i = 0; i < 9; i++)
        {
            set<int> rows;
            for(int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;

                if (rows.find(board[i][j]) == rows.end() && columns[j].find(board[i][j]) == columns[j].end())
                {
                    switch (j)
                    {
                        case 0:
                        case 1:
                        case 2:
                            if (threebythree[0].find(board[i][j]) == threebythree[0].end())
                            {
                                threebythree[0].insert(board[i][j]);
                            }
                            else
                            {
                                return false;
                            }
                            break;
                        case 3:
                        case 4:
                        case 5:
                            if (threebythree[1].find(board[i][j]) == threebythree[1].end())
                            {
                                threebythree[1].insert(board[i][j]);
                            }
                            else
                            {
                                return false;
                            }
                            break;
                        case 6:
                        case 7:
                        case 8:
                            if (threebythree[2].find(board[i][j]) == threebythree[2].end())
                            {
                                threebythree[2].insert(board[i][j]);
                            }
                            else
                            {
                                return false;
                            }
                            break;
                    }
                    rows.insert(board[i][j]);
                    columns[j].insert(board[i][j]);
                }
                else
                    return false;
            }
            if (i == 2 || i ==5)
            {
                threebythree[0].erase(threebythree[0].begin(), threebythree[0].end());
                threebythree[1].erase(threebythree[1].begin(), threebythree[1].end());
                threebythree[2].erase(threebythree[2].begin(), threebythree[2].end());
            }
        }
        return true;    
    }
};

int main()
{
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}};
    /* vector<vector<char>> board = {
  {'8','3','.','.','7','.','.','.','.'},
  {'6','.','.','1','9','5','.','.','.'},
  {'.','9','8','.','.','.','.','6','.'},
  {'8','.','.','.','6','.','.','.','3'},
  {'4','.','.','8','.','3','.','.','1'},
  {'7','.','.','.','2','.','.','.','6'},
  {'.','6','.','.','.','.','2','8','.'},
  {'.','.','.','4','1','9','.','.','5'},
  {'.','.','.','.','8','.','.','7','9'}
}; */
    Solution S1;
    cout << S1.isValidSudoku(board) << endl;
}
#include<iostream>
#include<set>
#include<vector>
#include<map>

using namespace std;

class Solution {
private:
    map<pair<int,int>, set<int>> openBoxes;
public:

    void solveSudoku(vector<vector<char>>& board)
    {
        solveSudoku_stage1(board); //fill all the sure numbers recursively
        solveSudoku_stage2(board, openBoxes.size()); //backtrack
    }

    void solveSudoku_stage1(vector<vector<char>>& board)
    {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    set<int> possibilitiesForthisBox = getPossibilities(i,j, board);
                    if (possibilitiesForthisBox.size() == 1)
                    {
                        int theEntry = *possibilitiesForthisBox.begin();
                        board[i][j] = theEntry + '0';
                        revisit(i, j, theEntry, board);
                    }
                    else
                    {
                        openBoxes[{i,j}] =  possibilitiesForthisBox;
                    }
                }
            }
        }
    }

    bool solveSudoku_stage2(vector<vector<char>>& board, int numOpenBoxes)
    {

        if (!isValidSudoku(board))
            return false;
        if (numOpenBoxes != 0)
        {
            for(int i = 0; i < board.size(); i++)
            {
                for(int j = 0; j < board.size(); j++)
                {
                    if (board[i][j] == '.')
                    {
                        set<int> possibilies = openBoxes[{i,j}];
                        for (auto it = possibilies.begin(); it != possibilies.end(); it++)
                        {
                            board[i][j] = *it +'0';
                            if(!solveSudoku_stage2(board,numOpenBoxes-1))
                            {
                                board[i][j] = '.';
                            }
                            else
                            {
                                return true;
                            }
                        }
                        if (board[i][j] == '.') return false;
                    }
                }
            }
        }
        else
        {
            return true;
        }
        return false;
    }

    set<int> getPossibilities(int i, int j, vector<vector<char>>& board)
    {
        set<int> poss = {1,2,3,4,5,6,7,8,9};
        int k = i/3 *3 + j/3;
        vector<int> allinI = scan_i(i, board);
        vector<int> allinJ = scan_j(j, board);
        vector<int> allinK = scan_k(k, board);

        for(auto it = allinI.begin(); it != allinI.end(); it++)
        {
            poss.erase(*it);
        }
        for(auto it = allinJ.begin(); it != allinJ.end(); it++)
        {
            poss.erase(*it);
        }
        for(auto it = allinK.begin(); it != allinK.end(); it++)
        {
            poss.erase(*it);
        }
        return poss;
    }

    vector<int> scan_i(int i, vector<vector<char>>& board)
    {
        vector<int> res;
        for(int j = 0; j < board[0].size(); j++)
        {
            if(board[i][j] != '.')
            {
                res.push_back(board[i][j] - '0');
            }
        }
        return res;
    }

    vector<int> scan_j(int j, vector<vector<char>>& board)
    {
        vector<int> res;
        for(int i = 0; i < board.size(); i++)
        {
            if(board[i][j] != '.')
            {
                res.push_back(board[i][j] - '0');
            }
        }
        return res;
    }

    vector<int> scan_k(int k, vector<vector<char>>& board)
    {
        int I = (k/3) * 3;
        int J = (k%3) * 3;
        int Imax = I + 3, Jmax = J + 3;
        vector<int> res;
        for(int i = I; i< Imax; i++)
        {
            for(int j = J; j< Jmax; j++)
            {
                if(board[i][j] != '.')
                {
                    res.push_back(board[i][j] - '0');
                }
            }
        }
        return res;
    }

    void revisit(int i, int j, int target, vector<vector<char>>& board)
    {
        vector<pair<int,int>> toBeErased;
        for(auto it = openBoxes.begin(); it != openBoxes.end(); it++)
        {
            int k = i/3 *3 + j/3;
            if (it->first.first == i || it->first.second == j || k == (it->first.first/3 *3 + it->first.second/3))
            {
                if(it->second.erase(target))
                if(it->second.size() == 1)
                {
                    toBeErased.push_back(it->first);
                    int temp_theEntry = *(it->second.begin());
                    board[it->first.first][it->first.second] = temp_theEntry + '0';

                    revisit(it->first.first, it->first.second, temp_theEntry, board);
                }
            }
        }
        for(auto it = toBeErased.begin(); it != toBeErased.end(); it ++)
        {
            openBoxes.erase(*it);
        }
    }

    bool isValidSudoku(vector<vector<char> > board)
    {
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9 ][9] = {0};
        
        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1;
                    int k = i / 3 * 3 + j / 3;

                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
        
        return true;
    }

    map<pair<int,int>, set<int>> returnOpenBoxes()
    {
        return openBoxes;
    }
};


int main()
{
    /* vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}}; */
    /* vector<vector<char>> board = {{'1','.','.','4','8','9','.','.','6'},
                                  {'7','3','.','.','.','.','.','4','.'},
                                  {'.','.','.','.','.','1','2','9','5'},
                                  {'.','.','7','1','2','.','6','.','.'},
                                  {'5','.','.','7','.','3','.','.','8'},
                                  {'.','.','6','.','9','5','7','.','.'},
                                  {'9','1','4','6','.','.','.','.','.'},
                                  {'.','2','.','.','.','.','.','3','7'},
                                  {'8','.','.','5','1','2','.','.','4'}}; */
    /* vector<vector<char>> board = {{'.','2','.','.','.','.','.','.','.'},
                                  {'.','.','.','6','.','.','.','.','3'},
                                  {'.','7','4','.','8','.','.','.','.'},
                                  {'.','.','.','.','.','3','.','.','2'},
                                  {'.','8','.','.','4','.','.','1','.'},
                                  {'6','.','.','5','.','.','.','.','.'},
                                  {'.','.','.','.','1','.','7','8','.'},
                                  {'5','.','.','.','.','9','.','.','.'},
                                  {'.','.','.','.','.','.','.','4','.'}}; */
    /* vector<vector<char>> board = {{'2','.','.','3','.','.','.','.','.'},
                                  {'8','.','4','.','6','2','.','.','3'},
                                  {'.','1','3','8','.','.','2','.','.'},
                                  {'.','.','.','.','2','.','3','9','.'},
                                  {'5','.','7','.','.','.','6','2','1'},
                                  {'.','3','2','.','.','6','.','.','.'},
                                  {'.','2','.','.','.','9','1','4','.'},
                                  {'6','.','1','2','5','.','8','.','9'},
                                  {'.','.','.','.','.','1','.','.','2'}}; */
    vector<vector<char>> board = {{'.','.','9','7','4','8','.','.','.'},{'7','.','.','.','.','.','.','.','.'},{'.','2','.','1','.','9','.','.','.'},{'.','.','7','.','.','.','2','4','.'},{'.','6','4','.','1','.','5','9','.'},{'.','9','8','.','.','.','3','.','.'},{'.','.','.','8','.','3','.','2','.'},{'.','.','.','.','.','.','.','.','6'},{'.','.','.','2','7','5','9','.','.'}};
    cout << "-------------------------------------" <<endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << "| "<< board[i][j] << " ";
        }
        cout << "|"<<endl << "-------------------------------------" <<endl;
    }
    cout << endl <<endl;
    Solution S1;
    S1.solveSudoku(board);
    map<pair<int,int>, set<int>> openBoxes = S1.returnOpenBoxes();
    cout << "-------------------------------------" <<endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
                cout << "| "<< board[i][j] << " ";
            else
            {
                cout << "|{";
                for(auto k = openBoxes[{i,j}].begin(); k != openBoxes[{i,j}].end(); k++)
                {
                    cout << *k;
                }
                cout << "}";
            }
            
        }
        cout << "|"<<endl << "-------------------------------------" <<endl;
    }
}
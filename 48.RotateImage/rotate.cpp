#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int size = matrix.size();
        rotate(matrix, 0, size);
    }

    void rotate(vector<vector<int>>& matrix, int r, int size)
    {
        if (size <=1)
        {
            return;
        }
        else
        {
            for(int j = r; j < r + size-1; j++)
            {
                swap(matrix[r][j], matrix[j][r + size-1]);
                swap(matrix[r][j], matrix[r+size-1][r+size-1-(j-r)]);
                swap(matrix[r][j], matrix[r+size-1-(j-r)][r]);
            }
            rotate(matrix, r+1, size-2);
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    Solution S1;
    S1.rotate(matrix);

    for(auto i = matrix.begin(); i != matrix.end(); i++)
    {
        for(auto j = i->begin(); j != i->end(); j++)
        {
            cout << *j << " ";
        }
        cout << endl;
    }
}
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> res;
        if(root)
        {
            dfs(root, res);
        }
        return res;
    }

    void dfs(TreeNode* root, vector<int>& res)
    {
        if(root->left) dfs(root->left, res);
        if (root->right) dfs(root->right, res);
        res.push_back(root->val);
    }
};

int main()
{
    TreeNode three(3);
    TreeNode two(2, &three, nullptr);
    TreeNode one(1, nullptr, &two);

    Solution S1;
    vector<int> res = S1.postorderTraversal(&one);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}
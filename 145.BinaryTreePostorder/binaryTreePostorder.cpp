#include<iostream>
#include<vector>
#include<stack>

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
        stack<TreeNode*> s;
        TreeNode *node, *last;
        vector<int> v;
        while(root || !s.empty())
        {
            if(root)
            {
                s.push(root);
                root = root->left;
            }
            else
            {
                TreeNode* node = s.top();
                if(node->right && node->right != last)
                {
                    root = node->right;
                }
                else
                {
                    last = node;
                    v.push_back(last->val);
                    s.pop();
                }
            }
        }
        return v;
    }
};

int main()
{
    TreeNode five(5), six(6), seven(7);
    TreeNode four(4, &five, nullptr);
    TreeNode two(2, &four, &six);
    TreeNode three(3, nullptr, &seven);
    TreeNode one(1, &two, &three);

    Solution S1;
    vector<int> res = S1.postorderTraversal(&one);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}
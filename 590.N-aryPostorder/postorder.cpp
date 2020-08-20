#include<iostream>
#include<queue>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<int> postorder(Node* root)
    {
        vector<int> res;
        if(root)
        {
            dfs(root, res);
        }
        return res;
    }

    void dfs(Node* root, vector<int>& res)
    {

        for(int i = 0; i < root->children.size(); i++)
        {
            dfs(root->children[i], res);
        }
        res.push_back(root->val);
    }
};

int main()
{
    Node six(6), five(5);
    Node three(3, {&five, &six});
    Node two(2), four(4);
    Node one(1, {&three, &two, &four});
    Solution S1;
    vector<int> res = S1.postorder(&one);
    for(auto it = res.begin(); it != res.end(); it++)
    {
        cout << *it << " ";
    }
}

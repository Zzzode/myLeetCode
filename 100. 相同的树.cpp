#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;

        bool res = true;

        vector<TreeNode *> sp;
        vector<TreeNode *> sq;

        sp.push_back(p);
        sq.push_back(q);

        while (p || !sp.empty() || q || !sq.empty())
        {
            if (p && q)
            {
                // visit p
                if (p->val != q->val)
                    return false;

                sp.push_back(p);
                sq.push_back(q);

                p = p->left;
                q = q->left;
            }
            else if (!p && !q)
            {
                p = sp.back()->right;
                q = sq.back()->right;

                sp.pop_back();
                sq.pop_back();
            }
            else
                return false;
        }

        return res;
    }
};

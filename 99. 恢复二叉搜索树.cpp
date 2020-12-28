#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int       val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  void recoverTree(TreeNode* root) {
    if (!root)
      return;

    vector<TreeNode*> s;
    vector<int>       list;
    TreeNode*         p     = root;
    int               index = 0;

    while (p || !s.empty()) {
      if (p) {
        s.push_back(p);
        p = p->left;
      } else {
        p = s.back();
        // visit p;
        cout << p->val << endl;
        list.push_back(p->val);

        s.pop_back();
        p = p->right;
      }
    }

    sort(list.begin(), list.end());
    p = root;

    while (p || !s.empty()) {
      if (p) {
        s.push_back(p);
        p = p->left;
      } else {
        p = s.back();
        // visit p;
        p->val = list[index];
        index++;

        s.pop_back();
        p = p->right;
      }
    }
  }
};
// 3 1 2
// 1 3 2 4

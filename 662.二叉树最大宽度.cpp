/*
@lc app=leetcode.cn id=662 lang=cpp
 *
[662] 二叉树最大宽度
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
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

// @lc code=start
class Solution {
public:
  int widthOfBinaryTree(TreeNode* root) {
    if (!root)
      return 0;

    queue<pair<TreeNode*, unsigned long long>> q;

    int ans = 1;
    q.emplace(root, 1);

    while (!q.empty()) {
      int size = q.size();

      ans = max(int(q.back().second - q.front().second + 1), ans);

      for (int i = 0; i < size; i++) {
        TreeNode*          node = q.front().first;
        unsigned long long pos  = q.front().second;
        q.pop();
        if (node->left)
          q.emplace(node->left, 2 * pos);
        if (node->right)
          q.emplace(node->right, 2 * pos + 1);
      }
    }
    return ans;
  }
};
// @lc code=end

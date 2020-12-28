/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */
#include <algorithm>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int       val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
class Solution {
public:
  int minDepth(TreeNode* root) {
    int res = 1e9;

    function<void(TreeNode * node, int depth)> dfs = [&](TreeNode* node,
                                                         int       depth) {
      // visit node
      if (node == nullptr)
        res = 0;
      else if (!node->left && !node->right)
        res = min(depth, res);
      else {
        if (node->left)
          dfs(node->left, depth + 1);
        if (node->right)
          dfs(node->right, depth + 1);
      }
    };
    dfs(root, 1);

    return res;
  }
};
// @lc code=end

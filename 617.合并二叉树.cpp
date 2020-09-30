/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
 */
#include "Header.h"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1)
      return t2;
    else if (!t2)
      return t1;
    else
      t1->val += t2->val;

    TreeNode* root = t1;
    dfs(t1, t2);

    return root;
  }

  inline void dfs(TreeNode* node1, TreeNode* node2) {
    // visit left
    if (!node1->left && node2->left) {
      node1->left = new TreeNode(node2->left->val);
    } else if (node1->left && node2->left)
      node1->left->val += node2->left->val;
    if (node1->left && node2->left)
      dfs(node1->left, node2->left);

    // visit right
    if (!node1->right && node2->right)
      node1->right = new TreeNode(node2->right->val);
    else if (node1->right && node2->right)
      node1->right->val += node2->right->val;
    if (node1->right && node2->right)
      dfs(node1->right, node2->right);
  };
};
// @lc code=end

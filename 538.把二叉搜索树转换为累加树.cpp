/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
  TreeNode* convertBST(TreeNode* root) {
    int sum = 0;
    TreeNode* ptr = nullptr;
    TreeNode* h = root;

    while (root != nullptr) {
      if (root->right != nullptr) {
        ptr = root->right;
        while (ptr->left != nullptr && ptr->left != root)
          ptr = ptr->left;

        if (ptr->left == nullptr) {
          ptr->left = root;
          root = root->right;
        } else {
          root->val += sum;
          sum = root->val;
          ptr->left = nullptr;
          root = root->left;
        }
      } else {
        root->val += sum;
        sum = root->val;
        root = root->left;
      }
    }

    return h;
  }
};
// @lc code=end

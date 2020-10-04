#include "Header.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 private:
  unordered_map<int, int> hash;

 public:
  bool isEvenOddTree(TreeNode* root) {
    return dfs(root, 0);
  }

  inline bool dfs(TreeNode* node, int height) {
    // visit node
    if (!node) return true;
    if (node->val % 2 == height % 2) return false;

    if (hash.count(height)) {
      if (height % 2) {
        if (node->val < hash[height])
          hash[height] = node->val;
        else
          return false;
      } else {
        if (node->val > hash[height])
          hash[height] = node->val;
        else
          return false;
      }
    } else
      hash[height] = node->val;

    return dfs(node->left, height + 1) && dfs(node->right, height + 1);
  }
};

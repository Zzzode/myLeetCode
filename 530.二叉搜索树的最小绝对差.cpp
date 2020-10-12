/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 *
 * https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (54.62%)
 * Likes:    142
 * Dislikes: 0
 * Total Accepted:    23.7K
 * Total Submissions: 40.3K
 * Testcase Example:  '[1,null,3,2]'
 *
 * 给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。
 *
 *
 *
 * 示例：
 *
 * 输入：
 *
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   /
 * ⁠  2
 *
 * 输出：
 * 1
 *
 * 解释：
 * 最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中至少有 2 个节点。
 * 本题与 783
 * https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/ 相同
 *
 *
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
  int getMinimumDifference(TreeNode* root) {
    TreeNode *cur = root, *prev = nullptr;
    int v = -1, ans = INT32_MAX;
    while (cur != NULL) {
      if (cur->left == NULL) {
        ans = v == -1 ? ans : min(ans, cur->val - v);
        v = cur->val;
        cur = cur->right;
      } else {
        // find predecessor
        prev = cur->left;
        while (prev->right != NULL && prev->right != cur) prev = prev->right;
        if (prev->right == NULL) {
          prev->right = cur;
          cur = cur->left;
        } else {
          prev->right = NULL;
          ans = min(ans, cur->val - v);
          v = cur->val;
          cur = cur->right;
        }
      }
    }
    return ans;
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (55.17%)
 * Likes:    344
 * Dislikes: 0
 * Total Accepted:    98.7K
 * Total Submissions: 174.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 *
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 *
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 *
 * 返回锯齿形层序遍历如下：
 *
 *
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    int dep = 0;
    vector<vector<int>> ans;
    deque<pair<TreeNode*, int>> q;
    q.emplace_back(root, 0);

    while (!q.empty()) {
      pair<TreeNode*, int> node;
      if (q.front().second == q.back().second) dep = q.front().second;
      if (dep % 2) {
        node = q.back();
        q.pop_back();
      } else {
        node = q.front();
        q.pop_front();
      }

      if (node.first) {
        if (ans.size() < dep + 1) ans.push_back({node.first->val});
        else
          ans.back().push_back(node.first->val);

        if (dep % 2) {
          q.emplace_front(node.first->right, dep + 1);
          q.emplace_front(node.first->left, dep + 1);
        } else {
          q.emplace_back(node.first->left, dep + 1);
          q.emplace_back(node.first->right, dep + 1);
        }
      }
    }

    return ans;
  }
};
// @lc code=end

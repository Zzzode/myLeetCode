/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (60.95%)
 * Likes:    343
 * Dislikes: 0
 * Total Accepted:    86K
 * Total Submissions: 141K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 *
 * 说明: 叶子节点是指没有子节点的节点。
 *
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 *
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 *
 *
 * 返回:
 *
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
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
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> ans;
    vector<int> tmp;

    function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int count) {
      // visit node
      tmp.push_back(node->val);
      count += node->val;
      if (count == sum && !node->left && !node->right)
        ans.push_back(tmp);

      if (node->left) {
        dfs(node->left, count);
        tmp.pop_back();
      }
      if (node->right) {
        dfs(node->right, count);
        tmp.pop_back();
      }
    };

    if (!root)
      return ans;
    dfs(root, 0);

    return ans;
  }
};
// @lc code=end

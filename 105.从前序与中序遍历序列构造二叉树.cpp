/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (68.13%)
 * Likes:    749
 * Dislikes: 0
 * Total Accepted:    127.4K
 * Total Submissions: 186K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 *
 * 注意:
 * 你可以假设树中没有重复的元素。
 *
 * 例如，给出
 *
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 *
 * 返回如下的二叉树：
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty()) return nullptr;

    TreeNode* node = new TreeNode(preorder[0]);
    if (preorder.size() == 1) return node;

    int dis = distance(inorder.begin(),
                       find(inorder.begin(), inorder.end(), node->val));
    vector<int> p1, p2, i1, i2;

    if (dis > 0) {
      p1 = vector<int>{preorder.begin() + 1, preorder.begin() + dis + 1};
      i1 = vector<int>{inorder.begin(), inorder.begin() + dis};
    }
    if (dis < preorder.size()) {
      p2 = vector<int>{preorder.begin() + dis + 1, preorder.end()};
      i2 = vector<int>{inorder.begin() + dis + 1, inorder.end()};
    }

    node->left = buildTree(p1, i1);
    node->right = buildTree(p2, i2);

    return node;
  }
};
// @lc code=end

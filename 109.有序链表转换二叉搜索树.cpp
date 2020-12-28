/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
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
// Definition for singly-linked list.
struct ListNode {
  int       val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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
  TreeNode* sortedListToBST(ListNode* head) {
    TreeNode*   root = nullptr;
    vector<int> list;

    while (head) {
      list.push_back(head->val);
      head = head->next;
    }

    if (list.empty())
      return root;
    else
      return Create(root, list, 0, list.size() - 1);
  }

  /// 创建AVL树
  inline TreeNode*
  Create(TreeNode* root, vector<int>& list, int low, int high) {
    int mid = (low + high) / 2;

    root       = new TreeNode(list[mid]);
    root->left = mid > low ? Create(root->left, list, low, mid - 1) : nullptr;
    root->right =
        mid < high ? Create(root->right, list, mid + 1, high) : nullptr;

    // Print(root);
    return root;
    ;
  }

  TreeNode* LL_Rotation(TreeNode* node) {
    TreeNode* temp = node->left;
    node->left     = temp->right;
    temp->right    = node;

    return temp;
  }

  TreeNode* RR_Rotation(TreeNode* node) {
    TreeNode* temp = node->right;
    node->right    = temp->left;
    temp->left     = node;
    return temp;
  }

  TreeNode* RL_Rotation(TreeNode* node) {
    node->right = LL_Rotation(node->right);
    return RR_Rotation(node);
  }

  TreeNode* LR_Rotation(TreeNode* node) {
    node->left = RR_Rotation(node->left);
    return LL_Rotation(node);
  }

  inline int Height(TreeNode* p) {
    if (p == nullptr)
      return 0;
    int i = Height(p->left);
    int j = Height(p->right);
    return i > j ? i + 1 : j + 1;
  }

  // 返回某个节点的平衡因子
  int BalanceFactor(TreeNode* p) {
    return Height(p->left) - Height(p->right);
  }

  // 对某个结点进行平衡操作
  TreeNode* Balancee(TreeNode* node) {
    int bf = BalanceFactor(node);
    if (bf > 1) {  //左子树更高
      if (BalanceFactor(node->left) > 0)
        node = LL_Rotation(node);
      else
        node = LR_Rotation(node);
    } else if (bf < -1) {  //右子树更高
      if (BalanceFactor(node->right) > 0)
        node = RL_Rotation(node);
      else
        node = RR_Rotation(node);
    }

    return node;
  }

  inline TreeNode* Insert(TreeNode* node, const int k) {
    if (node == nullptr)
      node = new TreeNode(k);
    else if (k > node->val) {  // 需要在右子树上插入新的结点
      node->right = Insert(node->right, k);
      node        = Balancee(node);
    } else if (k < node->val) {  //需要在左子树上插入新的结点
      node->left = Insert(node->left, k);
      node       = Balancee(node);
    }

    return node;
  }

  ///输出该排序树
  void Print(TreeNode* root) {
    cout << "中序遍历为： ";
    MidOrder(root);
    cout << endl;
    cout << "先序遍历为： ";
    PreOrder(root);
    cout << endl;
  }

  ///先序遍历输出
  void PreOrder(TreeNode* p) {
    if (p != NULL) {
      cout << p->val << " ";
      PreOrder(p->left);
      PreOrder(p->right);
    }
  }
  ///中序遍历输出。
  void MidOrder(TreeNode* p) {
    if (p != NULL) {
      MidOrder(p->left);
      cout << p->val << " ";
      MidOrder(p->right);
    }
  }
};
// @lc code=end

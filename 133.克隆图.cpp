/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  vector<Node *> neighbors;

  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }

  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }

  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

// @lc code=start
class Solution {
public:
  Solution() { tmp.resize(101, nullptr); }

  Node *cloneGraph(Node *node) { return dfs(node); }

  Node *dfs(Node *node) {
    // visit node
    if (node == nullptr)
      return node;

    if (tmp[node->val] != nullptr)
      return tmp[node->val];

    Node *clone = new Node(node->val);
    tmp[node->val] = clone;

    for (auto neighbor : node->neighbors) {
      Node *neighborClone = dfs(neighbor);
      clone->neighbors.push_back(neighborClone);
    }

    return clone;
  }

private:
  vector<Node *> tmp;
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */
#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int depth;
  string val;
  TreeNode *child[3];
  bool visited;

  TreeNode() : val(""), visited(false), depth(0) {
    for (int i = 0; i < 3; i++)
      child[i] = nullptr;
  }
  TreeNode(string x, int depth) : val(x), visited(false), depth(depth) {
    for (int i = 0; i < 3; i++)
      child[i] = nullptr;
  }
  TreeNode(string x, TreeNode *left, TreeNode *middle, TreeNode *right,
           int depth)
      : val(x), visited(false), depth(depth) {
    child[0] = left;
    child[1] = middle;
    child[2] = right;
  }
};

// @lc code=start
class Solution {
public:
  Solution() { root = new TreeNode(); }

  void initTree(TreeNode *p, string s) {
    if (12 - 3 * (p->depth) < s.length() || s.length() < 4 - (p->depth))
      return;

    for (int i = 0; i < s.length(); i++) {
      if (s.length() - i - 1 <= 9 - 3 * p->depth && valid(s.substr(0, i + 1))) {
        p->child[i] = new TreeNode(s.substr(0, i + 1), p->depth + 1);
        // cout << "depth = " << p->child[i]->depth << ", substr = " <<
        // p->child[i]->val << endl;
        if (i + 1 == s.length())
          break;
        initTree(p->child[i], s.substr(i + 1));
      }

      if (i == 2)
        break;
    }

    if (p->child[0] == nullptr && p->child[1] == nullptr &&
        p->child[2] == nullptr) {
      delete p;
      p = nullptr;
    }
  }

  vector<string> restoreIpAddresses(string s) {
    initTree(root, s);
    TreeNode *p = root;

    for (int i = 0; i < 3; i++) {
      if (p->child[i])
        DFS(p->child[i], "");
    }

    for (auto str : res) {
      cout << str << endl;
      _res.push_back(str);
    }

    return _res;
  }

  void DFS(TreeNode *p, string s) {
    // visit p;
    s += p->val;
    cout << "depth = " << p->depth << ", str = " << p->val << endl;
    if (p->depth == 4)
      // cout << "debug tmp = " << tmp << endl;
      res.emplace(s);
    else
      s += '.';

    for (int i = 0; i < 3; i++) {
      if (p->child[i])
        DFS(p->child[i], s);
    }
  }

  bool valid(TreeNode *p) {
    int num = stoi(p->val);
    if (p->val.length() != valCount(num) || num > 255)
      return false;

    return true;
  }

  bool valid(string s) {
    int num = stoi(s);
    if (s.length() != valCount(num) || num > 255)
      return false;

    return true;
  }

  int valCount(int num) {
    int count = 0;
    do {
      num /= 10;
      count++;
    } while (num != 0);

    return count;
  }

private:
  set<string> res;
  vector<string> _res;
  TreeNode *root;
};
// @lc code=end

int main() {
  Solution solution;
  vector<string> res;
  string s("25525511135");
  // cin >> s;

  res = solution.restoreIpAddresses(s);

  return 0;
}

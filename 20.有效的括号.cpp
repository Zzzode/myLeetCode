/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
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
// @lc code=start
class Solution {
public:
  bool isValid(string s) {
    vector<char> sp;

    if (s.empty())
      return true;
    if (s.length() % 2 != 0)
      return false;

    sp.push_back(s.front());
    for (int i = 1; i < s.length(); i++) {
      if (sp.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}'))
        return false;

      if (s[i] == ')') {
        if (sp.back() == '(')
          sp.pop_back();
        else
          return false;
      } else if (s[i] == ']') {
        if (sp.back() == '[')
          sp.pop_back();
        else
          return false;
      } else if (s[i] == '}') {
        if (sp.back() == '{')
          sp.pop_back();
        else
          return false;
      } else
        sp.push_back(s[i]);
    }

    if (sp.empty())
      return true;
    else
      return false;
  }
};
// @lc code=end

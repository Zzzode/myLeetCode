/*
 * @lc app=leetcode.cn id=1513 lang=cpp
 *
 * [1513] 仅含 1 的子串数
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
  int numSub(string s) {
    int res = 0, count = 0;

    for (char c : s)
      c == '1' ? res = (++count + res) % (int)(1e9 + 7) : count = 0;

    return res;
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
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
// @lc code=start
class Solution {
public:
  int countSubstrings(string s) {
    if (s.length() < 2)
      return s.size();

    string str;
    str = '$';  //防止越界
    for (auto ch : s) {
      str += "#";
      str += ch;
    }
    str += "#@";

    int length = str.length();
    int res    = 0;
    int right  = 0;
    int pos    = 0;

    vector<int> dp(length, 1);

    for (int i = 1; i < length - 1; i++) {
      if (i < right)
        dp[i] = min(dp[2 * pos - i], right - i);

      while (str[i - dp[i]] == str[i + dp[i]])
        dp[i]++;

      if (i + dp[i] > right) {
        right = i + dp[i];
        pos   = i;
      }

      res += dp[i] / 2;
    }

    return res;
  }
};
// @lc code=end

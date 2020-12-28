/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */
#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int countBinarySubstrings(string s) {
    int res   = 0;
    int count = 1, last = 0;

    for (int i = 1; i < s.length(); i++) {
      if (s[i] == s[i - 1])
        count++;
      else {
        res += min(count, last);
        last  = count;
        count = 1;
      }
    }
    res += min(count, last);

    return res;
  }
};
// @lc code=end

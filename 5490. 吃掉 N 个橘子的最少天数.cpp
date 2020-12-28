/*
 * @lc app=leetcode.cn id=5490 lang=cpp
 *
 * [5490] 吃掉 N 个橘子的最少天数
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
// f(n) = min{n, f(n / 3) + 1 + n % 3, f(n / 2) + 1 + n % 2}
class Solution {
public:
  int minDays(int n) {
    unordered_map<int, int> m;
    function<int(int)> dfs = [&](int n) -> int {
      if (n == 0)
        return 0;
      if (m.count(n))
        return m[n];
      return m[n] = min({1 + n % 2 + dfs(n / 2), 1 + n % 3 + dfs(n / 3), n});
    };
    return dfs(n);
  }
};
// @lc code=end

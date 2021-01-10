/*
 * @lc app=leetcode.cn id=440 lang=cpp
 *
 * [440] 字典序的第K小数字
 *
 * https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/description/
 *
 * algorithms
 * Hard (35.56%)
 * Likes:    178
 * Dislikes: 0
 * Total Accepted:    9.6K
 * Total Submissions: 26.7K
 * Testcase Example:  '13\n2'
 *
 * 给定整数 n 和 k，找到 1 到 n 中字典序第 k 小的数字。
 *
 * 注意：1 ≤ k ≤ n ≤ 10^9。
 *
 * 示例 :
 *
 *
 * 输入:
 * n: 13   k: 2
 *
 * 输出:
 * 10
 *
 * 解释:
 * 字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8,
 * 9]，所以第二小的数字是 10。
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
public:
  int findKthNumber(int n, int k) {
    int num = 1;
    k--;

    while (k) {
      long long count = 0, l = num, r = num + 1;
      while (l <= n) {
        count += min((long long)n + 1, r) - l;
        l *= 10;
        r *= 10;
      }
      if (count <= k) {
        num++;
        k -= count;
      } else {
        num *= 10;
        k--;
      }
    }
    // dfs(n, k, num);

    return num;
  }

  bool dfs(int& n, int& k, int& num) {
    k--;

    if (k == 0) return true;

    if (num * 10 <= n) {
      num *= 10;
      if (dfs(n, k, num)) return true;
      else {
        num /= 10;
      }
    }

    if (num % 10 < 9 && num + 1 <= n) {
      num++;
      if (dfs(n, k, num)) return true;
    }

    return false;
  }
};
// @lc code=end

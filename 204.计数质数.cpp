/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 *
 * https://leetcode-cn.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (35.66%)
 * Likes:    493
 * Dislikes: 0
 * Total Accepted:    88.1K
 * Total Submissions: 245.6K
 * Testcase Example:  '10'
 *
 * 统计所有小于非负整数 n 的质数的数量。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 10
 * 输出：4
 * 解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 *
 *
 * 示例 2：
 *
 * 输入：n = 0
 * 输出：0
 *
 *
 * 示例 3：
 *
 * 输入：n = 1
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= n <= 5 * 10^6
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
public:
  int countPrimes(int n) {
    vector<long long> isPrime(n, 1);
    int ans = 0;
    for (long long i = 2; i < n; ++i) {
      if (isPrime[i]) {
        ans++;
        for (long long j = i * i; j < n; j += i) isPrime[j] = 0;
      }
    }
    return ans;
  }
};
// @lc code=end

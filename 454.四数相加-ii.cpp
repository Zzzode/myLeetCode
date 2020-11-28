/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 *
 * https://leetcode-cn.com/problems/4sum-ii/description/
 *
 * algorithms
 * Medium (56.69%)
 * Likes:    280
 * Dislikes: 0
 * Total Accepted:    46K
 * Total Submissions: 80.2K
 * Testcase Example:  '[1,2]\n[-2,-1]\n[-1,2]\n[0,2]'
 *
 * 给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k,
 * l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
 *
 * 为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500
 * 。所有整数的范围在 -2^28 到 2^28 - 1 之间，最终结果不会超过 2^31 - 1 。
 *
 * 例如:
 *
 *
 * 输入:
 * A = [ 1, 2]
 * B = [-2,-1]
 * C = [-1, 2]
 * D = [ 0, 2]
 *
 * 输出:
 * 2
 *
 * 解释:
 * 两个元组如下:
 * 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
 * 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
 *
 *
 */
#include "Header.h"
// @lc code=start
using ll = long long;
class Solution {
 public:
  int fourSumCount(vector<int>& A,
                   vector<int>& B,
                   vector<int>& C,
                   vector<int>& D) {
    int n = A.size();
    int ans = 0;
    unordered_map<ll, ll> sum1;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) sum1[A[i] + B[j]]++;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (sum1.count(0 - C[i] - D[j])) ans += sum1[0 - C[i] - D[j]];
      }
    }

    return ans;
  }
};
// @lc code=end

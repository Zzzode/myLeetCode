/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 *
 * https://leetcode-cn.com/problems/sort-array-by-parity-ii/description/
 *
 * algorithms
 * Easy (68.26%)
 * Likes:    156
 * Dislikes: 0
 * Total Accepted:    55.8K
 * Total Submissions: 79.1K
 * Testcase Example:  '[4,2,5,7]'
 *
 * 给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。
 *
 * 对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i
 * 也是偶数。
 *
 * 你可以返回任何满足上述条件的数组作为答案。
 *
 *
 *
 * 示例：
 *
 * 输入：[4,2,5,7]
 * 输出：[4,5,2,7]
 * 解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= A.length <= 20000
 * A.length % 2 == 0
 * 0 <= A[i] <= 1000
 *
 *
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
 public:
  vector<int> sortArrayByParityII(vector<int>& A) {
    int n = A.size();
    vector<int> ans(n);
    int l = 0, r = 1;
    for (int i = 0; i < n; i++) {
      if (A[i] % 2) ans[r] = A[i], r += 2;
      else
        ans[l] = A[i], l += 2;
    }

    return ans;
  }
};
// @lc code=end

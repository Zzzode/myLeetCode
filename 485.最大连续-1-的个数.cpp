/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续1的个数
 *
 * https://leetcode-cn.com/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (56.75%)
 * Likes:    136
 * Dislikes: 0
 * Total Accepted:    58.6K
 * Total Submissions: 103.2K
 * Testcase Example:  '[1,0,1,1,0,1]'
 *
 * 给定一个二进制数组， 计算其中最大连续1的个数。
 *
 * 示例 1:
 *
 *
 * 输入: [1,1,0,1,1,1]
 * 输出: 3
 * 解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
 *
 *
 * 注意：
 *
 *
 * 输入的数组只包含 0 和1。
 * 输入数组的长度是正整数，且不超过 10,000。
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int len = nums.size();
    int l = 0, r = 0;
    int ans = 0;
    for (int i = 0; i < len; i++) {
      if (nums[i]) {
        r = i;
        ans = max(ans, r - l + 1);
      } else {
        l = i;
        l++;
      }
    }

    return ans;
  }
};
// @lc code=end

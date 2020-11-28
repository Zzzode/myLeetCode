/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 *
 * https://leetcode-cn.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (62.71%)
 * Likes:    830
 * Dislikes: 0
 * Total Accepted:    251.8K
 * Total Submissions: 398.6K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * 给定一个数组 nums，编写一个函数将所有 0
 * 移动到数组的末尾，同时保持非零元素的相对顺序。
 *
 * 示例:
 *
 * 输入: [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 *
 * 说明:
 *
 *
 * 必须在原数组上操作，不能拷贝额外的数组。
 * 尽量减少操作次数。
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int n = nums.size(), l = 0, r = 0;
    while (r < n) {
      while (l < n && nums[l] != 0) { l++, r = r < l ? l : r; }
      while (r < n && nums[r] == 0) { r++; }
      if (r != n) { swap(nums[l], nums[r]); }
    }
  }
};
// @lc code=end

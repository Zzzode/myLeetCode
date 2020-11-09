/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 *
 * https://leetcode-cn.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (34.54%)
 * Likes:    728
 * Dislikes: 0
 * Total Accepted:    97.7K
 * Total Submissions: 282K
 * Testcase Example:  '[1,2,3]'
 *
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 *
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 *
 * 必须原地修改，只允许使用额外常数空间。
 *
 * 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 *
 */
#include "Header.h"
// @lc code=start
#define all(x) (x).begin(), (x).end()
class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int n = nums.size();

    for (int i = n - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) {
        int j = n - 1;
        while (j > i && nums[j] <= nums[i]) j--;
        swap(nums[j], nums[i]);
        reverse(nums.begin() + i + 1, nums.end());
        return;
      }
    }

    return reverse(all(nums));
  }
};
// @lc code=end

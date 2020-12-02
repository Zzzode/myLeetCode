/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (40.57%)
 * Likes:    678
 * Dislikes: 0
 * Total Accepted:    153.8K
 * Total Submissions: 377.9K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值
 * target。找出给定目标值在数组中的开始位置和结束位置。
 *
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 *
 * 进阶：
 *
 *
 * 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 *
 * 示例 2：
 *
 *
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 *
 * 示例 3：
 *
 *
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * -109 
 * nums 是一个非递减数组
 * -109 
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans(2, -1);
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (nums[mid] > target) {
        r = mid - 1;
      } else if (nums[mid] < target) {
        l = mid + 1;
      } else {
        int lr = mid, rl = mid;
        while (l <= lr || rl <= r) {
          int midl = (l + lr) / 2, midr = (rl + r) / 2;
          if (nums[midl] < target) {
            l = midl + 1;
          } else {
            lr = midl - 1;
          }
          if (nums[midr] > target) {
            r = midr - 1;
          } else {
            rl = midr + 1;
          }
        }
        ans[0] = l, ans[1] = r;
        break;
      }
    }

    return ans;
  }
};
// @lc code=end

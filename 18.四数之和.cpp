/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (35.99%)
 * Likes:    582
 * Dislikes: 0
 * Total Accepted:    111.7K
 * Total Submissions: 290.1K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n
 * 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素
 * a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 *
 * 注意：
 *
 * 答案中不可以包含重复的四元组。
 *
 * 示例：
 *
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 *
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    if (n < 4) return {};

    set<vector<int>> se;
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 3; i++) {
      int sum = nums[i];
      for (int j = i + 1; j < n - 2; j++) {
        sum += nums[j];
        for (int k = j + 1; k < n - 1; k++) {
          sum += nums[k];
          for (int p = k + 1; p < n; p++) {
            if (sum + nums[p] == target)
              se.insert({nums[i], nums[j], nums[k], nums[p]});
          }
          sum -= nums[k];
        }
        sum -= nums[j];
      }
    }
    for (auto& a : se) ans.emplace_back(a);
    return ans;
  }
};
// @lc code=end

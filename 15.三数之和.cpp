/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (29.57%)
 * Likes:    2686
 * Dislikes: 0
 * Total Accepted:    347.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c
 * ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
 *
 * 注意：答案中不可以包含重复的三元组。
 *
 *
 *
 * 示例：
 *
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 *
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int len = nums.size();
    if (len < 3) return {};

    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    if (nums[len - 1] < 0 || nums[0] > 0) return ans;
    // do
    for (int i = 0; i < len - 2; i++) {
      if (nums[i] > 0) break;
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      for (int j = i + 1, k = len - 1; nums[j] < 0 - nums[i], j < k; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;
        while (nums[i] + nums[j] + nums[k] > 0 && k > j + 1) k--;
        if (nums[i] + nums[j] + nums[k] == 0)
          ans.push_back({nums[i], nums[j], nums[k]});
      }
    }

    return ans;
  }
};
// @lc code=end

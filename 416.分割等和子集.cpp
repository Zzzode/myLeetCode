/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode-cn.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (43.45%)
 * Likes:    435
 * Dislikes: 0
 * Total Accepted:    60.1K
 * Total Submissions: 121.3K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 *
 * 注意:
 *
 *
 * 每个数组中的元素不会超过 100
 * 数组的大小不会超过 200
 *
 *
 * 示例 1:
 *
 * 输入: [1, 5, 11, 5] 22
 *
 * 输出: true
 *
 * 解释: 数组可以分割成 [1, 5, 5] 和 [11].
 *
 *
 *
 *
 * 示例 2:
 *
 * 输入: [1, 2, 3, 5] 11
 *
 * 输出: false
 *
 * 解释: 数组不能分割成两个元素和相等的子集.
 *
 *
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    if (nums.size() < 2) return false;

    int sum = 0, max = 0;
    for (auto& n : nums) {
      sum += n;
      max = std::max(n, max);
    }

    if (sum % 2) return false;
    int target = sum / 2;
    if (max > target) return false;

    int n = nums.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));
    // init
    for (int i = 0; i < n; i++) dp[i][0] = true;
    dp[0][nums[0]] = true;
    // dp
    for (int i = 1; i < n; i++) {
      int num = nums[i];
      for (int j = 1; j <= target; j++) {
        if (j > num) dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
        else
          dp[i][j] = dp[i - 1][j];
      }
    }
    return dp[n - 1][target];
  }
};

// 超时解法
class Solution1 {
 public:
  bool canPartition(vector<int>& nums) {
    if (nums.size() < 2) return false;
    sort(nums.rbegin(), nums.rend());
    int sum = 0;
    for (auto& n : nums) sum += n;
    int target = sum / 2;
    if (sum % 2) return false;
    if (nums[0] > target) return false;

    return dfs(nums, 0, 0, target);
  }

  inline bool dfs(vector<int>& nums, int i, int sum, int& target) {
    cout << sum << endl;
    if (i == nums.size()) return false;
    if (sum > target) return false;
    if (sum + nums[i] == target) return true;
    return dfs(nums, i + 1, sum + nums[i], target) ||
           dfs(nums, i + 1, sum, target);
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=659 lang=cpp
 *
 * [659] 分割数组为连续子序列
 *
 * https://leetcode-cn.com/problems/split-array-into-consecutive-subsequences/description/
 *
 * algorithms
 * Medium (42.90%)
 * Likes:    214
 * Dislikes: 0
 * Total Accepted:    17K
 * Total Submissions: 32.6K
 * Testcase Example:  '[1,2,3,3,4,5]'
 *
 * 给你一个按升序排序的整数数组
 * num（可能包含重复数字），请你将它们分割成一个或多个子序列，其中每个子序列都由连续整数组成且长度至少为
 * 3 。
 *
 * 如果可以完成上述分割，则返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 * 输入: [1,2,3,3,4,5]
 * 输出: True
 * 解释:
 * 你可以分割出这样两个连续子序列 :
 * 1, 2, 3
 * 3, 4, 5
 *
 *
 *
 *
 * 示例 2：
 *
 * 输入: [1,2,3,3,4,4,5,5]
 * 输出: True
 * 解释:
 * 你可以分割出这样两个连续子序列 :
 * 1, 2, 3, 4, 5
 * 3, 4, 5
 *
 *
 *
 *
 * 示例 3：
 *
 * 输入: [1,2,3,4,4,5]
 * 输出: False
 *
 *
 *
 *
 * 提示：
 *
 *
 * 输入的数组长度范围为 [1, 10000]
 *
 *
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
public:
  bool isPossible(vector<int>& nums) {
    map<int, int> ma;
    for (auto& num : nums) ma[num]++;
    auto iter = ma.begin();
    while (iter != ma.end()) { ; }
  }
};
// @lc code=end

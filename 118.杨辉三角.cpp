/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (67.81%)
 * Likes:    385
 * Dislikes: 0
 * Total Accepted:    120.1K
 * Total Submissions: 176.5K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 *
 *
 *
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 *
 * 示例:
 *
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    if (numRows == 0) return ans;
    ans.emplace_back(vector<int>{1});
    for (int i = 1; i < numRows; i++) {
      ans.emplace_back(vector<int>(i + 1, 1));
      for (int j = 1; j < i; j++) {
        ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
      }
    }
    return ans;
  }
};
// @lc code=end

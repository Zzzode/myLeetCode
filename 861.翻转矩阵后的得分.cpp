/*
 * @lc app=leetcode.cn id=861 lang=cpp
 *
 * [861] 翻转矩阵后的得分
 *
 * https://leetcode-cn.com/problems/score-after-flipping-matrix/description/
 *
 * algorithms
 * Medium (74.52%)
 * Likes:    88
 * Dislikes: 0
 * Total Accepted:    7K
 * Total Submissions: 9.3K
 * Testcase Example:  '[[0,0,1,1],[1,0,1,0],[1,1,0,0]]'
 *
 * 有一个二维矩阵 A 其中每个元素的值为 0 或 1 。
 *
 * 移动是指选择任一行或列，并转换该行或列中的每一个值：将所有 0 都更改为
 * 1，将所有 1 都更改为 0。
 *
 * 在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的得分就是这些数字的总和。
 *
 * 返回尽可能高的分数。
 *
 *
 *
 *
 *
 *
 * 示例：
 *
 * 输入：[[0,0,1,1],[1,0,1,0],[1,1,0,0]]
 * 输出：39
 * 解释：
 * 转换为 [[1,1,1,1],[1,0,0,1],[1,1,1,1]]
 * 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= A.length <= 20
 * 1 <= A[0].length <= 20
 * A[i][j] 是 0 或 1
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
public:
  int matrixScore(vector<vector<int>>& A) {
    int n = A.size(), len = A[0].size();

    vector<int> d(n, 0);
    for (int i = 0; i < n; i++) { d[i] = A[i][0] == 1; }

    int ans = n * pow(2, len - 1);
    for (int i = 1; i < len; i++) {
      int c = 0;
      for (int j = 0; j < n; j++) { c += d[j] ? !A[j][i] : A[j][i]; }
      ans += max(c, n - c) * pow(2, len - i - 1);
    }

    return ans;
  }
};
// @lc code=end

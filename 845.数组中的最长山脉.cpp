/*
 * @lc app=leetcode.cn id=845 lang=cpp
 *
 * [845] 数组中的最长山脉
 *
 * https://leetcode-cn.com/problems/longest-mountain-in-array/description/
 *
 * algorithms
 * Medium (36.43%)
 * Likes:    85
 * Dislikes: 0
 * Total Accepted:    7.8K
 * Total Submissions: 21.2K
 * Testcase Example:  '[2,1,4,7,3,2,5]'
 *
 * 我们把数组 A 中符合下列属性的任意连续子数组 B 称为 “山脉”：
 *
 *
 * B.length >= 3
 * 存在 0 < i < B.length - 1 使得 B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ...
 * > B[B.length - 1]
 *
 *
 * （注意：B 可以是 A 的任意子数组，包括整个数组 A。）
 *
 * 给出一个整数数组 A，返回最长 “山脉” 的长度。
 *
 * 如果不含有 “山脉” 则返回 0。
 *
 *
 *
 * 示例 1：
 *
 * 输入：[2,1,4,7,3,2,5]
 * 输出：5
 * 解释：最长的 “山脉” 是 [1,4,7,3,2]，长度为 5。
 *
 *
 * 示例 2：
 *
 * 输入：[2,2,2]
 * 输出：0
 * 解释：不含 “山脉”。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= A.length <= 10000
 * 0 <= A[i] <= 10000
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
 public:
  int longestMountain(vector<int>& A) {
    int ans = 0, left = 0, right = 0, max = 0;
    if (A.size() < 3) return 0;

    for (int i = 1; i < A.size(); ++i) {
      if (A[i] > A[i - 1]) {
        if (right != max) left = right;
        max = right = i;
      } else if (A[i] == A[i - 1])
        left = max = right = i;
      else {
        if (max != left) {
          right = i;
          ans = std::max(ans, right - left + 1);
        } else
          max = left = right = i;
      }
    }

    return ans;
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1018 lang=cpp
 *
 * [1018] 可被 5 整除的二进制前缀
 *
 * https://leetcode-cn.com/problems/binary-prefix-divisible-by-5/description/
 *
 * algorithms
 * Easy (47.40%)
 * Likes:    94
 * Dislikes: 0
 * Total Accepted:    30.5K
 * Total Submissions: 59.2K
 * Testcase Example:  '[0,1,1]'
 *
 * 给定由若干 0 和 1 组成的数组 A。我们定义 N_i：从 A[0] 到 A[i] 的第 i
 * 个子数组被解释为一个二进制数（从最高有效位到最低有效位）。
 *
 * 返回布尔值列表 answer，只有当 N_i 可以被 5 整除时，答案 answer[i]
 * 为 true，否则为 false。
 *
 *
 *
 * 示例 1：
 *
 * 输入：[0,1,1]
 * 输出：[true,false,false]
 * 解释：
 * 输入数字为 0, 01, 011；也就是十进制中的 0, 1, 3 。只有第一个数可以被 5
 * 整除，因此 answer[0] 为真。
 *
 *
 * 示例 2：
 *
 * 输入：[1,1,1]
 * 输出：[false,false,false]
 *
 *
 * 示例 3：
 *
 * 输入：[0,1,1,1,1,1]
 * 输出：[true,false,false,false,true,false]
 *
 *
 * 示例 4：
 *
 * 输入：[1,1,1,0,1]
 * 输出：[false,false,false,false,false]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= A.length <= 30000
 * A[i] 为 0 或 1
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
public:
  vector<bool> prefixesDivBy5(vector<int>& A) {
    int n = A.size(), pre = 0;
    vector<bool> ans(n, false);

    for (int i = 0; i < n; i++) {
      pre = (pre * 2 + A[i]) % 10;
      if (pre == 0 || pre == 5) ans[i] = true;
    }

    return ans;
  }
};
// @lc code=end

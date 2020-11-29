/*
 * @lc app=leetcode.cn id=976 lang=cpp
 *
 * [976] 三角形的最大周长
 *
 * https://leetcode-cn.com/problems/largest-perimeter-triangle/description/
 *
 * algorithms
 * Easy (55.86%)
 * Likes:    125
 * Dislikes: 0
 * Total Accepted:    41.6K
 * Total Submissions: 69.8K
 * Testcase Example:  '[2,1,2]'
 *
 * 给定由一些正数（代表长度）组成的数组
 * A，返回由其中三个长度组成的、面积不为零的三角形的最大周长。
 *
 * 如果不能形成任何面积不为零的三角形，返回 0。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：[2,1,2]
 * 输出：5
 *
 *
 * 示例 2：
 *
 * 输入：[1,2,1]
 * 输出：0
 *
 *
 * 示例 3：
 *
 * 输入：[3,2,3,4]
 * 输出：10
 *
 *
 * 示例 4：
 *
 * 输入：[3,6,2,3]
 * 输出：8
 *
 *
 *
 *
 * 提示：
 *
 *
 * 3 <= A.length <= 10000
 * 1 <= A[i] <= 10^6
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
  public:
    int largestPerimeter(vector<int>& A) {
        int n = A.size();
        sort(A.begin(), A.end());
        for (int i = n - 1; i >= 2; i--) {
            if (A[i - 1] + A[i - 2] > A[i]) return A[i - 2] + A[i - 1] + A[i];
        }
        return 0;
    }
};
// @lc code=end

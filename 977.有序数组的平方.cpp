/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 *
 * https://leetcode-cn.com/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (71.51%)
 * Likes:    150
 * Dislikes: 0
 * Total Accepted:    67.3K
 * Total Submissions: 91.9K
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * 给定一个按非递减顺序排序的整数数组
 * A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。
 *
 *
 *
 * 示例 1：
 *
 * 输入：[-4,-1,0,3,10]
 * 输出：[0,1,9,16,100]
 *
 *
 * 示例 2：
 *
 * 输入：[-7,-3,2,3,11]
 * 输出：[4,9,9,49,121]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= A.length <= 10000
 * -10000 <= A[i] <= 10000
 * A 已按非递减顺序排序。
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& A) {
    int len = A.size();
    for (int tail = len - 1; tail >= 0; tail--) {
      if (pow(A[0], 2) > pow(A[tail], 2)) {
        int tmp = A[tail];
        A[tail] = pow(A[0], 2);
        A[0] = tmp;
      } else
        A[tail] = pow(A[tail], 2);
    }
    return A;
  }
};
// @lc code=end

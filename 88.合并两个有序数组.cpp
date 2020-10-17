/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (48.68%)
 * Likes:    660
 * Dislikes: 0
 * Total Accepted:    219.3K
 * Total Submissions: 449.7K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1
 * 成为一个有序数组。
 *
 *
 *
 * 说明：
 *
 *
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2
 * 中的元素。
 *
 *
 *
 *
 * 示例：
 *
 *
 * 输入：
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 *
 * 输出：[1,2,2,3,5,6]
 *
 *
 *
 * 提示：
 *
 *
 * -10^9
 * nums1.length == m + n
 * nums2.length == n
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m - 1, p2 = n - 1;

    for (int i = m + n - 1; i >= 0, p2 >= 0; i--) {
      if (p1 < 0) swap(nums1[i], nums2[p2--]);
      else
        nums1[p1] >= nums2[p2] ? swap(nums1[i], nums1[p1--]) :
                                 swap(nums1[i], nums2[p2--]);
    }
  }
};
// @lc code=end

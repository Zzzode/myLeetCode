/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 *
 * https://leetcode-cn.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (70.78%)
 * Likes:    243
 * Dislikes: 0
 * Total Accepted:    101.2K
 * Total Submissions: 142.4K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组，编写一个函数来计算它们的交集。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2]
 *
 *
 * 示例 2：
 *
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[9,4]
 *
 *
 *
 * 说明：
 *
 *
 * 输出结果中的每个元素一定是唯一的。
 * 我们可以不考虑输出结果的顺序。
 *
 *
 */
#include "Header.h"
// @lc code=start
template <typename T> using v1 = vector<T>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2>;
template <typename T> using uset = unordered_set<T>;
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    int l1 = nums1.size(), l2 = nums2.size();
    uset<int> s1;
    uset<int> s2;
    v1<int> ans;
    for (auto& n : nums1) s1.emplace(n);
    for (auto& n : nums2) s2.emplace(n);
    for (auto& n : s2)
      if (s1.count(n)) ans.emplace_back(n);
    return ans;
  }
};
// @lc code=end

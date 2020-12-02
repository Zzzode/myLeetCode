/*
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
 *
 * https://leetcode-cn.com/problems/create-maximum-number/description/
 *
 * algorithms
 * Hard (32.47%)
 * Likes:    289
 * Dislikes: 0
 * Total Accepted:    15.8K
 * Total Submissions: 37.4K
 * Testcase Example:  '[3,4,6,5]\n[9,1,2,5,8,3]\n5'
 *
 * 给定长度分别为 m 和 n 的两个数组，其元素由 0-9 构成，表示两个自然数各位上的数字。现在从这两个数组中选出
 * k (k <= m + n)
 * 个数字拼接成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。
 *
 * 求满足该条件的最大数。结果返回一个表示该最大数的长度为 k 的数组。
 *
 * 说明: 请尽可能地优化你算法的时间和空间复杂度。
 *
 * 示例 1:
 *
 * 输入:
 * nums1 = [3, 4, 6, 5]
 * nums2 = [9, 1, 2, 5, 8, 3]
 * k = 5
 * 输出:
 * [9, 8, 6, 5, 3]
 *
 * 示例 2:
 *
 * 输入:
 * nums1 = [6, 7]
 * nums2 = [6, 0, 4]
 * k = 5
 * 输出:
 * [6, 7, 6, 0, 4]
 *
 * 示例 3:
 *
 * 输入:
 * nums1 = [3, 9]
 * nums2 = [8, 9]
 * k = 3
 * 输出:
 * [9, 8, 9]
 *
 */

// !tips 单调栈合并

#include "Header.h"
// @lc code=start
using pii = pair<int, int>;
class Solution {
public:
  //求单调栈
  vector<int> GetMonStack(vector<int>& nums, int length) {
    stack<int> s;
    int n = nums.size();
    int drop_num = n - length;
    for (int i = 0; i < n; ++i) {
      while (!s.empty() && s.top() < nums[i] && drop_num > 0) {
        s.pop();
        --drop_num;
      }
      if (s.size() < length) s.push(nums[i]);
      else
        --drop_num;
    }
    return [](stack<int> ss) {
      vector<int> res(ss.size(), 0);
      int i = ss.size() - 1;
      while (!ss.empty()) {
        res[i--] = ss.top();
        ss.pop();
      }
      return res;
    }(s);
  }
  //合并两个vector
  vector<int> MergeVector(vector<int>& one, vector<int>& two) {
    int size_one = one.size(), size_two = two.size();
    if (!size_one) return two;
    if (!size_two) return one;
    int a = 0, b = 0;
    int n = size_one + size_two, i = 0;
    vector<int> res(size_one + size_two, 0);
    while (i < n) {
      if (compare(one, a, two, b) > 0) res[i++] = one[a++];
      else
        res[i++] = two[b++];
    }
    return res;
  }
  //比较函数
  int compare(vector<int>& one, int index1, vector<int>& two, int index2) {
    int x = one.size(), y = two.size();
    while (index1 < x && index2 < y) {
      int tag = one[index1++] - two[index2++];
      if (tag != 0) return tag;
    }
    return (x - index1) - (y - index2);
  }
  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int size_num1 = nums1.size(), size_num2 = nums2.size();
    int start = max(0, k - size_num2), end = min(size_num1, k);
    vector<int> res(k, 0);
    for (int i = start; i <= end; i++) {
      vector<int> one(GetMonStack(nums1, i));
      vector<int> two(GetMonStack(nums2, k - i));
      vector<int> temp(MergeVector(one, two));
      if (compare(temp, 0, res, 0) > 0) res.swap(temp);
    }
    return res;
  }
};
// @lc code=end
int main() {
  Solution solution{};
  vector<int> nums1{3, 4, 6, 5};
  vector<int> nums2{9, 1, 2, 5, 8, 3};
  vector<int> ans = solution.maxNumber(nums1, nums2, 5);
  for (auto a : ans) cout << a << " ";
  //  cout << ans << endl;
  return 0;
}

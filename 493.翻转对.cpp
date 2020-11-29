/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 *
 * https://leetcode-cn.com/problems/reverse-pairs/description/
 *
 * algorithms
 * Hard (29.51%)
 * Likes:    202
 * Dislikes: 0
 * Total Accepted:    15.2K
 * Total Submissions: 49.1K
 * Testcase Example:  '[1,3,2,3,1]'
 *
 * 给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i,
 * j) 称作一个重要翻转对。
 *
 * 你需要返回给定数组中的重要翻转对的数量。
 *
 * 示例 1:
 *
 *
 * 输入: [1,3,2,3,1]
 * 输出: 2
 *
 *
 * 示例 2:
 *
 *
 * 输入: [2,4,3,5,1]
 * 输出: 3
 *
 *
 * 注意:
 *
 *
 * 给定数组的长度不会超过50000。
 * 输入数组中的所有数字都在32位整数的表示范围内。
 *
 *
 */
#include "Header.h"
// @lc code=start
class BIT {
 private:
  vector<int> tree;
  int n;

 public:
  BIT(int _n) : n(_n), tree(_n + 1) {}

  static constexpr int lowbit(int x) {
    return x & (-x);
  }

  void update(int x, int d) {
    while (x <= n) {
      tree[x] += d;
      x += lowbit(x);
    }
  }

  int query(int x) const {
    int ans = 0;
    while (x) {
      ans += tree[x];
      x -= lowbit(x);
    }
    return ans;
  }
};

class Solution {
 public:
  int reversePairs(vector<int>& nums) {
    set<long long> allNumbers;
    for (int x : nums) {
      allNumbers.emplace(x);
      allNumbers.emplace((long long)x * 2);
    }

    // 利用哈希表进行离散化
    unordered_map<long long, int> values;
    int idx = 0;
    for (long long x : allNumbers) { values[x] = ++idx; }

    int ret = 0;
    BIT bit(values.size());
    for (int i = 0; i < nums.size(); i++) {
      int left = values[(long long)nums[i] * 2], right = values.size();
      ret += bit.query(right) - bit.query(left);
      bit.update(values[nums[i]], 1);
    }
    return ret;
  }
};

class Solution1 {
 public:
  int reversePairsRecursive(vector<int>& nums, int left, int right) {
    if (left == right) {
      return 0;
    } else {
      int mid = (left + right) / 2;
      int n1 = reversePairsRecursive(nums, left, mid);
      int n2 = reversePairsRecursive(nums, mid + 1, right);
      int ret = n1 + n2;

      // 首先统计下标对的数量
      int i = left;
      int j = mid + 1;
      while (i <= mid) {
        while (j <= right && (long long)nums[i] > 2 * (long long)nums[j]) j++;
        ret += (j - mid - 1);
        i++;
      }

      // 随后合并两个排序数组
      vector<int> sorted(right - left + 1);
      int p1 = left, p2 = mid + 1;
      int p = 0;
      while (p1 <= mid || p2 <= right) {
        if (p1 > mid) {
          sorted[p++] = nums[p2++];
        } else if (p2 > right) {
          sorted[p++] = nums[p1++];
        } else {
          if (nums[p1] < nums[p2]) {
            sorted[p++] = nums[p1++];
          } else {
            sorted[p++] = nums[p2++];
          }
        }
      }
      for (int i = 0; i < sorted.size(); i++) { nums[left + i] = sorted[i]; }
      return ret;
    }
  }

  int reversePairs(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    return reversePairsRecursive(nums, 0, nums.size() - 1);
  }
};

// @lc code=end

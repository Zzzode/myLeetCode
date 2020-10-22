/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 *
 * https://leetcode-cn.com/problems/partition-labels/description/
 *
 * algorithms
 * Medium (72.24%)
 * Likes:    258
 * Dislikes: 0
 * Total Accepted:    22.3K
 * Total Submissions: 30.7K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * 字符串 S
 * 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。
 *
 *
 *
 * 示例 1：
 *
 * 输入：S = "ababcbacadefegdehijhklij"
 * 输出：[9,7,8]
 * 解释：
 * 划分结果为 "ababcbaca", "defegde", "hijhklij"。
 * 每个字母最多出现在一个片段中。
 * 像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
 *
 *
 *
 *
 * 提示：
 *
 *
 * S的长度在[1, 500]之间。
 * S只包含小写字母 'a' 到 'z' 。
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
 public:
  vector<int> partitionLabels(string S) {
    vector<int> ans;
    unordered_map<char, int> h;
    int len = S.length(), l = 0, r = 0;

    for (int i = 0; i < len; i++) h[S[i]] = i;
    for (int i = 0; i < len; ++i) {
      r = max(r, h[S[i]]);
      if (r == i) {
        ans.emplace_back(r - l + 1);
        l = r + 1;
      }
    }

    return ans;
  }
};

class Solution1 {
 public:
  vector<int> partitionLabels(string S) {
    unordered_map<char, vector<int>> h;
    vector<int> ans;
    int len = S.length();
    if (len == 1) return {1};

    for (int i = 0; i < len; i++) h[S[i]].emplace_back(i);

    for (int i = 0; i < len; ++i) {
      if (h[S[i]].size() == 1) ans.emplace_back(1);
      else {
        int r = h[S[i]].back();
        for (int j = i; j <= r; j++) { r = max(r, h[S[j]].back()); }
        ans.emplace_back(r - i + 1);
        i = r;
      }
    }

    return ans;
  }
};
// @lc code=end

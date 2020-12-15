/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (63.93%)
 * Likes:    572
 * Dislikes: 0
 * Total Accepted:    136K
 * Total Submissions: 209.9K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 *
 * 示例:
 *
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 *
 * 说明：
 *
 *
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size();
    vector<vector<string>> ans;
    unordered_map<string, int> hash;
    for (int i = 0; i < n; i++) {
      string t = strs[i];
      sort(t.begin(), t.end());
      if (hash.count(t)) ans[hash[t]].emplace_back(strs[i]);
      else {
        ans.push_back({strs[i]});
        hash[t] = ans.size() - 1;
      }
    }

    return ans;
  }
};
// @lc code=end

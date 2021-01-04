/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (39.64%)
 * Likes:    879
 * Dislikes: 0
 * Total Accepted:    98.1K
 * Total Submissions: 244.6K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s
 * 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 *
 * 注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "a", t = "a"
 * 输出："a"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * s 和 t 由英文字母组成
 *
 *
 *
 * 进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？
 */
#include "Header.h"
// @lc code=start
class Solution {
public:
  string minWindow(string s, string t) {
    vector<int> v(128, 0);
    for (int i = 0; i < t.length(); i++) v[t[i]]++;

    int len = 1e5 + 1, ans = 0, c = t.length();
    for (int l = 0, i = 0; i < s.length(); i++) {
      if (v[s[i]]-- > 0) c--;

      while (!c) {
        if (i - l + 1 < len) {
          ans = l;
          len = i - l + 1;
        }
        if (!v[s[l++]]++) c++;
      }
    }

    return len == 1e5 + 1 ? "" : s.substr(ans, len);
  }
};

class mySolution {
public:
  string minWindow(string s, string t) {
    deque<int> dq;
    unordered_map<char, int> hash;
    unordered_set<char> rem{t.begin(), t.end()};

    for (int i = 0; i < t.length(); i++) hash[t[i]]++;

    int l = 0;
    while (l < s.length() && !hash.count(s[l])) l++;

    int len = 1e5 + 1, ans = l;
    for (int i = l; i < s.length(); i++) {
      if (hash.count(s[i])) {
        dq.emplace_back(i);
        hash[s[i]]--;
        if (hash[s[i]] == 0) rem.erase(s[i]);
      }

      while (rem.empty()) {
        if (i - l + 1 < len) {
          ans = l;
          len = i - l + 1;
        }
        hash[s[l]]++;
        if (hash[s[l]] > 0 && !rem.count(s[l])) rem.emplace(s[l]);
        dq.pop_front();
        l = dq.front();
      }
    }

    if (len == 1e5 + 1) return "";
    else
      return s.substr(ans, len);
  }
};
// @lc code=end

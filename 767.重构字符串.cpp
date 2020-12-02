/*
 * @lc app=leetcode.cn id=767 lang=cpp
 *
 * [767] 重构字符串
 *
 * https://leetcode-cn.com/problems/reorganize-string/description/
 *
 * algorithms
 * Medium (43.12%)
 * Likes:    144
 * Dislikes: 0
 * Total Accepted:    11.8K
 * Total Submissions: 27.3K
 * Testcase Example:  '"aab"'
 *
 * 给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。
 *
 * 若可行，输出任意可行的结果。若不可行，返回空字符串。
 *
 * 示例 1:
 *
 *
 * 输入: S = "aab"
 * 输出: "aba"
 *
 *
 * 示例 2:
 *
 *
 * 输入: S = "aaab"
 * 输出: ""
 *
 *
 * 注意:
 *
 *
 * S 只包含小写字母并且长度在[1, 500]区间内。
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
public:
  string reorganizeString(string S) {
    int len = S.length();

    vector<int> vi(26, 0);
    for (char& ch : S) vi[ch - 'a']++;

    vector<pair<int, char>> vp;
    for (int i = 0; i < 26; i++) {
      if (vi[i]) { vp.emplace_back(vi[i], i + 'a'); }
    }
    sort(vp.begin(), vp.end());

    int mm = vp.back().first, res = len - mm;
    if (mm > res + 1) return "";

    vector<string> vs(vp.back().first, string(1, vp.back().second));
    vp.pop_back();
    int i = 0;
    while (!vp.empty()) {
      char ch = vp.back().second;
      vs[i] += ch;
      vp.back().first--;
      if (i == mm - 2) {
        i = vp.back().first ? mm - 1 : 0;
      } else
        i = (i + 1) % mm;
      if (!vp.back().first) vp.pop_back();
    }

    string ans;
    for (auto& v : vs) ans += v;

    return ans;
  }
};
// @lc code=end

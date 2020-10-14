/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 *
 * https://leetcode-cn.com/problems/find-common-characters/description/
 *
 * algorithms
 * Easy (68.80%)
 * Likes:    172
 * Dislikes: 0
 * Total Accepted:    40.3K
 * Total Submissions: 54.5K
 * Testcase Example:  '["bella","label","roller"]'
 *
 * 给定仅有小写字母组成的字符串数组
 * A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现
 * 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。
 *
 * 你可以按任意顺序返回答案。
 *
 *
 *
 * 示例 1：
 *
 * 输入：["bella","label","roller"]
 * 输出：["e","l","l"]
 *
 *
 * 示例 2：
 *
 * 输入：["cool","lock","cook"]
 * 输出：["c","o"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= A.length <= 100
 * 1 <= A[i].length <= 100
 * A[i][j] 是小写字母
 *
 *
 */
#include "Header.h"
// @lc code=start
using PII = pair<int, int>;
class Solution {
 public:
  vector<string> commonChars(vector<string>& A) {
    int len = A.size();
    vector<string> ans;
    unordered_map<string, PII> hash;
    unordered_map<string, PII> last;
    for (auto& ch : A[0]) {
      string c;
      c = ch;
      hash[c].first++;
      hash[c].second = 0;
      last[c] = hash[c];
    }

    for (int i = 1; i < len; i++) {
      for (auto& ch : A[i]) {
        string c;
        c = ch;
        if (hash.count(c) == 0) continue;
        if (hash[c].second != i) {
          if (hash[c].second != i - 1) {
            hash.erase(c);
            continue;
          }
          hash[c].second = i;
          hash[c].first = 1;
        } else
          hash[c].first = min(hash[c].first + 1, last[c].first);
      }
      last = hash;
    }

    for (auto& h : hash) {
      if (h.second.second != len - 1) continue;
      for (int i = h.second.first; i > 0; i--) ans.emplace_back(h.first);
    }

    return ans;
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 *
 * https://leetcode-cn.com/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Medium (42.60%)
 * Likes:    391
 * Dislikes: 0
 * Total Accepted:    40.3K
 * Total Submissions: 86.2K
 * Testcase Example:  '"bcabc"'
 *
 * 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证
 * 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
 *
 * 注意：该题与 1081
 * https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters
 * 相同
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "bcabc"
 * 输出："abc"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "cbacdcbc"
 * 输出："acdb"
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * s 由小写英文字母组成
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
public:
  string removeDuplicateLetters(string s) {
    int n = s.length();
    char head;
    unordered_set<char> se;
    for (int i = 0; i < n; i++) {
      if (head == -1) {
        se.emplace(s[i]);
        head = s[i];
      } else {
        if (se.count(s[i])) {
          if (s[i] > head) {
            se.erase(s[i]);
            se.emplace(s[i]);
          } else if (s[i] == head) {
            if ((se.begin() + se.size() - 1)) }
        } else {
          se.emplace(s[i]);
        }
      }
    }

    string ans;

    return ans;
  }
};
// @lc code=end

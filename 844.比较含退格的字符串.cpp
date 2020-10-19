/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 *
 * https://leetcode-cn.com/problems/backspace-string-compare/description/
 *
 * algorithms
 * Easy (50.97%)
 * Likes:    198
 * Dislikes: 0
 * Total Accepted:    42K
 * Total Submissions: 80.3K
 * Testcase Example:  '"ab#c"\n"ad#c"'
 *
 * 给定 S 和 T
 * 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。
 * # 代表退格字符。
 *
 * 注意：如果对空文本输入退格字符，文本继续为空。
 *
 *
 *
 * 示例 1：
 *
 * 输入：S = "ab#c", T = "ad#c"
 * 输出：true
 * 解释：S 和 T 都会变成 “ac”。
 *
 *
 * 示例 2：
 *
 * 输入：S = "ab##", T = "c#d#"
 * 输出：true
 * 解释：S 和 T 都会变成 “”。
 *
 *
 * 示例 3：
 *
 * 输入：S = "a##c", T = "#a#c"
 * 输出：true
 * 解释：S 和 T 都会变成 “c”。
 *
 *
 * 示例 4：
 *
 * 输入：S = "a#c", T = "b"
 * 输出：false
 * 解释：S 会变成 “c”，但 T 仍然是 “b”。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= S.length <= 200
 * 1 <= T.length <= 200
 * S 和 T 只含有小写字母以及字符 '#'。
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 你可以用 O(N) 的时间复杂度和 O(1) 的空间复杂度解决该问题吗？
 *
 *
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
 public:
  bool backspaceCompare(string S, string T) {
    int s = S.length() - 1, t = T.length() - 1;
    int c[2] = {0};
    bool ans = true;

    while ((s >= 0 || t >= 0) && ans) {
      do {
        c[0] = s < 0 ? 0 : c[0], c[1] = t < 0 ? 0 : c[1];
        while (c[0] > 0 && S[s] != '#') { c[0] = --s >= 0 ? c[0] - 1 : 0; }
        while (c[1] > 0 && T[t] != '#') { c[1] = --t >= 0 ? c[1] - 1 : 0; }
        while (s >= 0 && S[s] == '#') { c[0]++, s--; }
        while (t >= 0 && T[t] == '#') { c[1]++, t--; }
      } while (c[0] || c[1]);

      while (s >= 0 && t >= 0 && S[s] != '#' && T[t] != '#')
        if (S[s--] != T[t--]) ans = false;

      if (s < 0 && t >= 0 && ans) ans = T[t] != '#' ? false : true;
      if (t < 0 && s >= 0 && ans) ans = S[s] != '#' ? false : true;
    }

    return ans;
  }
};
/*
"bxj##tw"
"bxj###tw"
"rheyggodcclgstf"
"#rheyggodcclgstf"
"nzp#o#g"
"b#nzp#o#g"
"a#c"
"b"
"e##e#o##oyof##q"
"e##e#fq##o##oyof##q"
*/
// @lc code=end

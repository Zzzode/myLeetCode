/*
 * @lc app=leetcode.cn id=1202 lang=cpp
 *
 * [1202] 交换字符串中的元素
 *
 * https://leetcode-cn.com/problems/smallest-string-with-swaps/description/
 *
 * algorithms
 * Medium (34.63%)
 * Likes:    86
 * Dislikes: 0
 * Total Accepted:    5.3K
 * Total Submissions: 14.4K
 * Testcase Example:  '"dcab"\n[[0,3],[1,2]]'
 *
 * 给你一个字符串 s，以及该字符串中的一些「索引对」数组 pairs，其中 pairs[i]
 * = [a, b] 表示字符串中的两个索引（编号从 0 开始）。
 *
 * 你可以 任意多次交换 在 pairs 中任意一对索引处的字符。
 *
 * 返回在经过若干次交换后，s 可以变成的按字典序最小的字符串。
 *
 *
 *
 * 示例 1:
 *
 * 输入：s = "dcab", pairs = [[0,3],[1,2]]
 * 输出："bacd"
 * 解释：
 * 交换 s[0] 和 s[3], s = "bcad"
 * 交换 s[1] 和 s[2], s = "bacd"
 *
 *
 * 示例 2：
 *
 * 输入：s = "dcab", pairs = [[0,3],[1,2],[0,2]]
 * 输出："abcd"
 * 解释：
 * 交换 s[0] 和 s[3], s = "bcad"
 * 交换 s[0] 和 s[2], s = "acbd"
 * 交换 s[1] 和 s[2], s = "abcd"
 *
 * 示例 3：
 *
 * 输入：s = "cba", pairs = [[0,1],[1,2]]
 * 输出："abc"
 * 解释：
 * 交换 s[0] 和 s[1], s = "bca"
 * 交换 s[1] 和 s[2], s = "bac"
 * 交换 s[0] 和 s[1], s = "abc"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * 0 <= pairs.length <= 10^5
 * 0 <= pairs[i][0], pairs[i][1] < s.length
 * s 中只含有小写英文字母
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
public:
  string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    int n = pairs.size(), len = s.length();

    vector<vector<int>> g(len);
    for (auto& i : pairs) {
      g[i[0]].emplace_back(i[1]);
      g[i[1]].emplace_back(i[0]);
    }

    vector<int> vis(len, 0);
    for (int i = 0; i < len; i++) {
      if (!vis[i]) {
        vector<int> vv;
        string str;
        queue<int> q;
        q.emplace(i);
        vis[i] = 1;
        while (!q.empty()) {
          int node = q.front();
          q.pop();
          vv.emplace_back(node);
          str.push_back(s[node]);
          for (int& j : g[node]) {
            if (!vis[j]) {
              vis[j] = 1;
              q.emplace(j);
            }
          }
        }
        sort(str.begin(), str.end());
        sort(vv.begin(), vv.end());
        for (int j = 0; j < vv.size(); j++) { s[vv[j]] = str[j]; }
      }
    }

    return s;
  }
};
// @lc code=end

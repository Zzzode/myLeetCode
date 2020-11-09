/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 *
 * https://leetcode-cn.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (38.62%)
 * Likes:    256
 * Dislikes: 0
 * Total Accepted:    22.9K
 * Total Submissions: 59K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词列表的字典
 * wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。
 *
 * 说明：
 *
 *
 * 分隔时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 *
 *
 * 示例 1：
 *
 * 输入:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * 输出:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 *
 *
 * 示例 2：
 *
 * 输入:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * 输出:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * 解释: 注意你可以重复使用字典中的单词。
 *
 *
 * 示例 3：
 *
 * 输入:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出:
 * []
 *
 *
 */
#include "Header.h"
// @lc code=start
#define myAnswer
#ifdef myAnswer

#  define MOD 1000000007
#  define pb push_back
#  define eb emplace_back
#  define em emplace
#  define mp make_pair
#  define all(x) (x).begin(), (x).end()
#  define fi first
#  define se second

using ld = long double;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

template <typename T> using v1 = vector<T>;
template <typename T> using v2 = vector<vector<T>>;
template <typename T> using uset = unordered_set<T>;
template <typename T> using umset = unordered_multiset<T>;
template <typename T1, typename T2> using p2 = pair<T1, T2>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2>;

class Solution {
 public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    int len = s.length(), n = wordDict.size();
    uset<string> se{all(wordDict)};

    vector<bool> dp(len, false);
    dp[0] = se.count(string(1, s[0]));
    for (int i = 1; i < len; i++) {
      if (se.count(s.substr(0, i + 1))) {
        dp[i] = true;
        continue;
      }

      for (int j = 0; j < i; j++) {
        if (dp[j] && se.count(s.substr(j + 1, i - j))) {
          dp[i] = true;
          break;
        }
      }
    }
    if (!dp[len - 1]) return {};

    v1<string> ans;
    v2<p2<string, int>> ss(len);

    for (int i = 0; i < len; i++) {
      for (int j = i; j < len; j++) {
        string sub(s.substr(i, j - i + 1));
        if (se.count(sub)) ss[i].eb(sub, j);
      }
    }

    dfs(ss, ans, 0, "");

    return ans;
  }

  void dfs(v2<p2<string, int>>& ss, v1<string>& ans, int i, string str) {
    if (i == ss.size()) {
      ans.eb(str);
      return;
    }
    if (ss[i].empty()) return;

    for (int k = 0; k < ss[i].size(); k++) {
      string tmp = str.empty() ? ss[i][k].fi : (str + " " + ss[i][k].fi);
      dfs(ss, ans, ss[i][k].se + 1, tmp);
    }
  }
};

#endif
#undef myAnswer
// @lc code=end

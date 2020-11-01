#include "Header.h"

#define MOD 1000000007

using ull = unsigned long long;
template <typename T> using umset = unordered_multiset<T>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2>;
template <typename T> using v2 = vector<vector<T>>;
template <typename T> using v1 = vector<T>;

class Solution {
 public:
  int numWays(vector<string>& words, string target) {
    int n = words.size(), lw = words[0].size(), lt = target.length();
    v2<ull> dp(lt, v1<ull>(lw, 0));
    umap<int, umset<char>> h;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < lw; j++) h[j].emplace(words[i][j]);

    //

    return dp[lt - 1][lw - 1] % MOD;
  }
};

class Solution1 {
 public:
  int numWays(vector<string>& words, string target) {
    ull ans = 0;
    int n = words.size(), l = words[0].size(), lt = target.length();
    if (l < lt) return 0;

    umap<int, umset<char>> h;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < l; j++) h[j].emplace(words[i][j]);

    for (int i = 0; i <= l - lt; i++) ans += dfs(h, target, l, lt, i, 0);

    return ans % MOD;
  }

  ull dfs(umap<int, umset<char>>& h, string& t, int& l, int& lt, int i, int j) {
    ull count = h[i].count(t[j]);
    if (j == lt - 1 || !count) return count;

    ull sum = 0;
    for (int k = i + 1; k <= l - (lt - j - 1); k++)
      if (ull res = dfs(h, t, l, lt, k, j + 1)) sum += res;

    return sum * count;
  }
};
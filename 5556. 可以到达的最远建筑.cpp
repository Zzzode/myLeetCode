#include "Header.h"

#define MOD 1000000007

using ull = unsigned long long;
template <typename T> using umset = unordered_multiset<T>;
template <typename T> using uset = unordered_set<T>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2>;
template <typename T> using v2 = vector<vector<T>>;
template <typename T> using v1 = vector<T>;

class Solution {
 public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    int n = heights.size(), ans = 0;
    if (n == 1) return 1;

    // return dfs(heights, 1, bricks, ladders, 1);
  }

  //  int dfs(v1<int>& h, int i, int b, int l, int len) {
  //    if (i == h.size()) return len - 1;
  //    if (h[i] <= h[i - 1]) return dfs(h, i + 1, b, l, len + 1);
  //    int d = h[i] - h[i - 1];
  //    int r1 = 0, r2 = 0;
  //    if (b - d > 0) r1 = dfs(h, i + 1, b - d, l, len + 1);
  //    if (l > 0) r2 = dfs(h, i + 1, b, l - 1, len + 1);
  //    len -= r1 == 0 && r2 == 0 ? 1 : 0;
  //    return max({len, r1, r2});
  //  }
};
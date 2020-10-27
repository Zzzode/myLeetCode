#include "Header.h"

class Solution {
 public:
  int minimumEffortPath(vector<vector<int>>& he) {
    int len = he[0].size();
    int hei = he.size();
    if (len == 1 && hei == 1) return 0;

    l = 0, r = 1e6;
    while (l < r) {
      mid = (l + r) / 2;
      vector<vector<bool>> visited(hei, vector<bool>(len, false));
      if (dfs(he, visited, 0, 0, 0, he[0][0])) r = mid;
      else
        l = mid + 1;
    }

    return l;
  }

  bool dfs(vector<vector<int>>& he,
           vector<vector<bool>>& visited,
           int i,
           int j,
           int m,
           int pre) {
    if (i > he.size() - 1 || i < 0 || j > he[0].size() - 1 || j < 0 ||
        visited[i][j])
      return false;

    m = max(abs(he[i][j] - pre), m);
    if (m > mid) return false;
    if (i == he.size() - 1 && j == he[0].size() - 1) return true;

    visited[i][j] = true;
    int tmp = he[i][j];
    bool res = false;
    if (dfs(he, visited, i - 1, j, m, tmp) ||
        dfs(he, visited, i + 1, j, m, tmp) ||
        dfs(he, visited, i, j - 1, m, tmp) ||
        dfs(he, visited, i, j + 1, m, tmp))
      res = true;

    return res;
  }

 private:
  int l, r, mid;
  int ans;
};

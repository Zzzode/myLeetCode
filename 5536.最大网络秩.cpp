#include "Header.h"

class Solution {
 public:
  int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    int ans = 0;
    vector<vector<int>> g(n, vector<int>(n));
    vector<int> sz(n, 0);
    for (auto& r : roads) {
      sz[r[0]]++;
      sz[r[1]]++;
      g[r[0]][r[1]] = g[r[1]][r[0]] = 1;
    }

    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) ans = max(ans, sz[i] + sz[j] - g[i][j]);

    return ans;
  }
};

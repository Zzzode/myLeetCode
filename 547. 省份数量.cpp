#include "Header.h"

class Solution {
public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    if (isConnected.empty()) return 0;

    int ans = 0;
    vector<int> v(isConnected.size(), 0);
    for (int i = 0; i < isConnected.size(); i++) {
      if (!v[i]) {
        bfs(isConnected, v, i);
        ans++;
      }
    }

    return ans;
  }

  void bfs(vector<vector<int>>& g, vector<int>& v, int i) {
    queue<int> q;
    v[i] = 1;

    for (int j = 0; j < g[i].size(); j++) {
      if (!v[j] && g[i][j]) {
        q.emplace(j);
        while (!q.empty()) {
          int node = q.front();
          v[node] = 1;
          q.pop();
          for (int k = 0; k < g[node].size(); k++) {
            if (!v[k] && g[node][k]) q.emplace(k);
          }
        }
      }
    }
  }
};

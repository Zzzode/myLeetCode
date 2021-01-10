#include "Header.h"

class Solution {
public:
  int minimumHammingDistance(vector<int>& source,
                             vector<int>& target,
                             vector<vector<int>>& allow) {
    int n = source.size(), ans = n;

    vector<vector<int>> g(n);
    for (auto& i : allow) {
      g[i[0]].emplace_back(i[1]);
      g[i[1]].emplace_back(i[0]);
    }

    vector<int> vis(n, 0);
    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        q.emplace(i);
        vis[i] = 1;
        vector<int> nA, nB;
        while (!q.empty()) {
          int node = q.front();
          q.pop();
          nA.emplace_back(source[node]);
          nB.emplace_back(target[node]);
          for (int& j : g[node]) {
            if (!vis[j]) {
              vis[j] = 1;
              q.emplace(j);
            }
          }
        }

        sort(nA.begin(), nA.end());
        sort(nB.begin(), nB.end());
        for (int j = 0, k = 0; j < nA.size() && k < nB.size();) {
          if (nA[j] == nB[k]) ans--, j++, k++;
          else if (nA[j] < nB[k])
            j++;
          else
            k++;
        }
      }
    }

    return ans;
  }
};

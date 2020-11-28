#include "Header.h"

class Solution {
 public:
  int minimumEffort(vector<vector<int>>& tasks) {
    int n = tasks.size();
    int sum = 0, mm = 0;
    vector<pair<int, int>> ts;
    map<int, vector<pair<int, int>>> ma;
    for (int i = 0; i < n; i++) {
      sum += tasks[i][0];
      mm = max(mm, tasks[i][1]);
      ma[tasks[i][1] - tasks[i][0]].emplace_back(tasks[i][1], tasks[i][0]);
    }

    int ans = max(mm, sum);
    int tmp = ans;
    map<int, vector<pair<int, int>>>::reverse_iterator iter = ma.rbegin();
    while (iter != ma.rend()) {
      sort(iter->second.rbegin(), iter->second.rend());
      auto& ts = iter->second;
      for (int i = 0; i < ts.size(); i++) {
        if (tmp < ts[i].first) {
          ans += ts[i].first - tmp;
          tmp = ts[i].first;
        }

        if (tmp >= ts[i].second) tmp -= ts[i].second;
        else {
          ans += ts[i].second - tmp;
          tmp = 0;
        }
      }
      iter++;
    }

    return ans;
  }
};

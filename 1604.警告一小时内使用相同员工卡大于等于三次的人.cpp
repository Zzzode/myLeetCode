#include "Header.h"

class Solution {
 public:
  vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
    vector<string> ans;
    unordered_map<string, vector<int>> hash;
    int n = keyName.size();
    for (int i = 0; i < n; i++) {
      hash[keyName[i]].emplace_back(stoi(keyTime[i].substr(0, 2)) * 60 +
                                    stoi(keyTime[i].substr(3, 2)));
    }
    for (auto& h : hash) {
      if (h.second.size() < 3) continue;
      sort(h.second.begin(), h.second.end());
      for (int i = 0, j = 2; j < h.second.size(); i++, j++) {
        if (h.second[j] - h.second[i] <= 60) {
          ans.emplace_back(h.first);
          break;
        }
      }
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};

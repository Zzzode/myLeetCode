#include "Header.h"

class Solution {
public:
  int countPairs(vector<int>& deli) {
    int n = deli.size();
    vector<int> se;
    for (int i = 0; i <= 22; i++) { se.emplace_back(pow(2, i)); }
    sort(deli.begin(), deli.end());

    vector<pair<long long, long long>> v;
    unordered_map<int, int> hash;
    v.emplace_back(deli[0], 1);
    for (int i = 1; i < n; i++) {
      hash[deli[i]]++;
      if (v.back().first == deli[i]) v.back().second++;
      else {
        v.emplace_back(deli[i], 1);
      }
    }

    long long ans = 0;
    for (int i = 0; i < v.size(); i++) {
      for (int j = 0; j < se.size(); j++) {
        if (se[j] < 2 * v[i].first) continue;
        if (se[j] == 2 * v[i].first) {
          ans += v[i].second * (v[i].second - 1) / 2 % MOD;
        } else {
          if (hash.count(se[j] - v[i].first)) {
            ans += v[i].second * hash[se[j] - v[i].first] % MOD;
          }
        }
        ans % MOD;
      }
    }

    return ans % MOD;
  }

private:
  long long MOD = 1e9 + 7;
};

#include "Header.h"

using pii = pair<int, int>;
#define fi first
#define se second

class Solution {
 public:
  int countSubstrings(string s, string t) {
    int ans = 0;
    int ls = s.length(), lt = t.length();
    // int l = min(ls, lt);
    vector<pii> l1;
    vector<pii> l2;
    // vector<vector<int>> dp(lt, vector<int>(lt, 0));
    for (int i = 0; i < ls; i++) {
      for (int j = i; j < ls; j++) {
        if (j - i + 1 > lt) break;
        l1.emplace_back(i, j);
      }
    }

    for (int i = 0; i < lt; i++) {
      for (int j = i; j < lt; j++) {
        if (j - i + 1 > ls) break;
        l2.emplace_back(i, j);
      }
    }

    for (int i = 0; i < l1.size(); i++) {
      int n1 = l1[i].se - l1[i].fi + 1;
      for (int j = 0; j < l2.size(); j++) {
        int n2 = l2[j].se - l2[j].fi + 1;
        if (n2 != n1) continue;
        int count = 0;
        for (int k = 0; k < n1; k++) {
          if (s[l1[i].fi + k] != t[l2[j].fi + k]) count++;
          if (count > 1) break;
        }
        ans += count == 1 ? 1 : 0;
      }
    }

    return ans;
  }
};

#include "Header.h"

class Solution {
public:
  int minCost(string s, vector<int>& cost) {
    if (s.length() == 1)
      return cost[0];

    int ans = 0;
    for (int i = 0; i < s.length() - 1; i++) {
      if (s[i] == s[i + 1]) {
        if (cost[i] <= cost[i + 1])
          ans += cost[i];
        else {
          ans += cost[i + 1];
          cost[i + 1] = cost[i];
        }
      }
    }

    return ans;
  }
};

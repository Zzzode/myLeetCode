#include "Header.h"

class Solution {
 public:
  int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    int n = points.size();

    set<int> s;
    for (auto& p : points) s.emplace(p[0]);
    int ans = 0;
    int tmp = *s.begin();
    for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++) {
      if (iter == s.begin()) continue;
      ans = max(ans, *iter - tmp);
      tmp = *iter;
    }

    return ans;
  }
};

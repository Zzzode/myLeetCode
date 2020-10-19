#include "Header.h"

class Solution {
 public:
  // d = sqrt((x1-x2)^2+(y1-y2)^2)
  vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
    int max = 0;
    vector<int> ans(2);
    for (int x = 0; x <= 50; x++) {
      for (int y = 0; y <= 50; y++) {
        int r = 0;
        for (auto& t : towers) {
          double d = distance(x, y, t);
          if (d <= radius) r += (double)t[2] / (double)(1 + d);
        }
        if (r > max) {
          ans[0] = x, ans[1] = y;
          max = r;
        }
      }
    }
    return ans;
  }
  double distance(int x, int y, vector<int>& t) {
    return sqrt(pow(x - t[0], 2) + pow(y - t[1], 2));
  }
};

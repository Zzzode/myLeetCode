#include "Header.h"

#define PI 3.14159265
#define angl(x) (x) / PI * 180

class Solution {
 public:
  int visiblePoints(vector<vector<int>>& ps, int angle, vector<int>& lc) {
    int ans = 0;
    vector<double> v;
    for (auto p : ps) {
      if (p[0] == lc[0] && p[1] == lc[1]) {
        ans++;
        continue;
      } else {
        double at = atan2(p[1] - lc[1], p[0] - lc[0]);
        if (at < 0)
          v.emplace_back(2 * PI + at);
        else
          v.emplace_back(at);
      }
    }
    sort(v.begin(), v.end());

    int count = 0, max = 0;
    int head = 0, tail = 0;
    int n = v.size();
    for (int i = 0; i < n; i++) v.emplace_back(v[i] + 2 * PI);
    while (head < n) {
      if (angl(v[tail] - v[head]) <= angle) {
        count++;
        tail++;
      } else {
        if (head == tail) tail++;
        head++;
        count = tail - head;
      }
      if (count > max) max = count;
    }

    return ans + max;
  }
};

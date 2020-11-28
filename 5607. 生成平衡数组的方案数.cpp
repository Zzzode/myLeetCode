#include "Header.h"

class Solution {
 public:
  int waysToMakeFair(vector<int>& nums) {
    int n = nums.size();
    vector<int> o(n, 0), e(n, 0);
    o[0] = 0, e[0] = nums[0];
    for (int i = 1; i < n; i++) {
      if (i % 2) {
        o[i] = o[i - 1] + nums[i];
        e[i] = e[i - 1];
      } else {
        e[i] = e[i - 1] + nums[i];
        o[i] = o[i - 1];
      }
    }
    // cout << o[n - 1] << " " << e[n - 1] << endl;

    int ans = 0;
    if (o[n - 1] == e[n - 1] - nums[0]) ans++;
    for (int i = 1; i < n; i++) {
      if (i % 2) {
        int t1 = o[i] - nums[i] + e[n - 1] - e[i];
        int t2 = e[i] + o[n - 1] - o[i];
        if (t1 == t2) ans++;
      } else {
        int t1 = o[i] + e[n - 1] - e[i];
        int t2 = e[i] - nums[i] + o[n - 1] - o[i];
        if (t1 == t2) ans++;
      }
    }

    return ans;
  }
};

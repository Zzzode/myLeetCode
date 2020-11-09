#include "Header.h"

#define all(x) (x).begin(), (x).end()
class Solution {
 public:
  int getMaximumGenerated(int n) {
    vector<int> nums(n + 1, 0);
    if (n == 0) return 0;
    if (n == 1) return 1;
    nums[1] = 1;
    for (int i = 2; i <= n; i++) {
      if (i % 2) nums[i] = nums[(i - 1) / 2] + nums[(i - 1) / 2 + 1];
      else
        nums[i] = nums[i / 2];
    }

    return *max_element(all(nums));
  }
};

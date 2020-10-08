#include "Header.h"

class Solution {
 public:
  int maxNonOverlapping(vector<int>& nums, int target) {
    int len = nums.size(), sum = 0;
    vector<int> dp(len + 1, 0);
    unordered_map<int, int> dict{{0, 0}};

    for (int i = 1; i <= len; i++) {
      sum += nums[i - 1];
      dp[i] = dict.count(sum - target) ?
                  max(dp[i - 1], dp[dict[sum - target]] + 1) :
                  dp[i - 1];
      dict[sum] = i;
    }

    return dp[len];
  }
};

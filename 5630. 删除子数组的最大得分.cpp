#include "Header.h"

class Solution {
public:
  int maximumUniqueSubarray(vector<int>& nums) {
    int n = nums.size(), ans = 0;
    unordered_set<int> se;

    int sum = 0;
    for (int i = 0, j = 0; i < n; i++) {
      for (; j < n && !se.count(nums[j]); j++) {
        sum += nums[j];
        se.emplace(nums[j]);
      }
      ans = max(ans, sum);
      sum -= nums[i];
      se.erase(nums[i]);
    }

    return ans;
  }
};

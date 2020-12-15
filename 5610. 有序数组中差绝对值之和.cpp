#include "Header.h"

class Solution {
public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int n = nums.size();
    vector<int> tmp(nums);
    for (int i = 1; i < n; i++) { tmp[i] += tmp[i - 1]; }
    for (int i = 0; i < n; i++) {
      int l = nums[i] * i, r = nums[i] * (n - i - 1), res = 0;
      res += i > 0 ? l - tmp[i - 1] : 0;
      res += i < n - 1 ? tmp[n - 1] - tmp[i] - r : 0;
      nums[i] = res;
    }

    return nums;
  }
};

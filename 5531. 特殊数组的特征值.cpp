#include "Header.h"

class Solution {
 public:
  int specialArray(vector<int>& nums) {
    int size = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = size; i > 0; i--) {
      if (nums[size - i] >= i) {
        if (size - i > 0) {
          if (nums[size - i - 1] < i) return i;
        } else
          return i;
      }
    }
    return -1;
  }
};

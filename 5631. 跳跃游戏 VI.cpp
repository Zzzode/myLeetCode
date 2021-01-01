#include "Header.h"

class Solution {
public:
  int maxResult(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> f(n);
    f[0] = nums[0];
    deque<int> q = {0};
    for (int i = 1; i < n; ++i) {
      while (i - q.front() > k) { q.pop_front(); }
      f[i] = f[q.front()] + nums[i];
      while (!q.empty() && f[i] >= f[q.back()]) { q.pop_back(); }
      q.push_back(i);
    }
    return f[n - 1];
  }
};

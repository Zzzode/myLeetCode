#include "Header.h"

class Solution {
public:
  int minMoves(vector<int>& nums, int limit) {
    int n = nums.size();
    int l = 0, r = n - 1;
    int m = 0;

    vector<int> v;
    while (l < r) {
      v.emplace_back(nums[l] + nums[r]);
      l++, r--;
    }
    sort(v.begin(), v.end());
    if (v.front() == v.back()) return 0;

    int ans = 0, tmp = v.size();
    unordered_map<int, int> ma;
    for (int i = 0; i < v.size(); i++) ma[v[i]]++;
    for (auto& mm : ma) {
      if (mm.second > 2 * limit) {
        ans += 2 * mm.second;
        tmp -= mm.second;
      } else
        m = max(mm.second, m);
    }

    return ans + tmp - m;
  }
};

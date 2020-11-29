#include "Header.h"

#define se second
#define fi first
using pii = pair<int, int>;
template <typename T> using v1 = vector<T>;
class Solution {
 public:
  int minimumMountainRemovals(vector<int>& nums) {
    int n = nums.size();
    int ans = INT32_MAX;
    v1<pii> v;
    for (int i = 0; i < n; i++) { v.emplace_back(nums[i], i); }
    sort(v.begin(), v.end());
    //
    while (!v.empty()) {
      if (v.back().se != 0 && v.back().se != n - 1)
        dfs(nums, v.back().fi, {0, v.back().se - 1}, {v.back().se + 1, n - 1},
            ans);
      v.pop_back();
    }

    return ans;
  }

  void dfs(v1<int>& nums, int& m, pii l, pii r, int& ans) {
    int res = 0;
    if (l.se > l.fi) {
      int len = 1, n = (int)nums.size();
      if (n != 0) {
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; ++i) {
          if (nums[i] > d[len]) {
            d[++len] = nums[i];
          } else {
            int l = 1, r = len,
                pos = 0;  // 如果找不到说明所有的数都比 nums[i] 大，此时要更新
                          // d[1]，所以这里将 pos 设为 0
            while (l <= r) {
              int mid = (l + r) >> 1;
              if (d[mid] < nums[i]) {
                pos = mid;
                l = mid + 1;
              } else {
                r = mid - 1;
              }
            }
            d[pos + 1] = nums[i];
          }
        }
      }
    }
    if (r.se > r.fi) { ; }
    ans = min(ans, res);
  }
};

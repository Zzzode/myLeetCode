#include "Header.h"

class Solution {
public:
  int waysToSplit(vector<int>& a) {
    int n = a.size();
    vector<int> v(n + 1, 0);
    // 初始化前缀和数组
    for (int i = 1; i <= n; i++) { v[i] = v[i - 1] + a[i - 1]; }
    // 返回值 ret
    long long ret = 0;
    const int M = 1e9 + 7;

    for (int i = 1; i < n; i++) {
      // 特判
      if (v[i] * 3 > v[n]) break;

      // 第一次二分找右边界
      int l = i + 1, r = n - 1;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (v[n] - v[mid] < v[mid] - v[i]) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }

      // 第二次二分找左边界
      int ll = i + 1, rr = n - 1;
      while (ll <= rr) {
        int mid = (ll + rr) / 2;
        if (v[mid] - v[i] < v[i]) {
          ll = mid + 1;
        } else {
          rr = mid - 1;
        }
      }
      ret += l - ll;
    }
    return ret % M;
  }
};

class mySolution {
public:
  int waysToSplit(vector<int>& nums) {
    int n = nums.size(), br = n - 2;

    for (int i = 1; i < n; i++) nums[i] += nums[i - 1];
    while (br && nums[n - 1] - nums[br] < ceil(nums[br] / 2)) br--;

    long long ans = 0;
    for (; br >= 1; br--) {
      int l = 1, r = br, mm = nums[n - 1] - nums[br];
      while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid - 1] < nums[br] - nums[mid - 1]) l = mid + 1;
        else
          r = mid;
      }
      if (nums[l - 1] > nums[br] - nums[l - 1]) r--;
      if (mm < nums[br] - nums[r - 1]) continue;

      l = 1;
      int tr = r;
      while (l < tr) {
        int mid = (l + tr) / 2;
        if (nums[br] - nums[l - 1] <= mm) tr = mid;
        else
          l = mid + 1;
      }

      cout << l << " " << r << " " << br << endl;
      ans += r - l + 1;
      ans %= MOD;
    }

    return ans % MOD;
  }

private:
  long long MOD = 1e9 + 7;
};

#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename T> using uset = unordered_set<T>;
template <typename T> using umset = unordered_multiset<T>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2>;
template <typename T> using v2 = vector<vector<T>>;
template <typename T1, typename T2> using p2 = pair<T1, T2>;
template <typename T> using v1 = vector<T>;

using ld = long double;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

// ----------- solution ----------- //

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans(2, -1);
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (nums[mid] > target) {
        r = mid - 1;
      } else if (nums[mid] < target) {
        l = mid + 1;
      } else {
        int lr = mid, rl = mid;
        while (l <= lr || rl <= r) {
          int midl = (l + lr) / 2, midr = (rl + r) / 2;
          if (nums[midl] < target) {
            l = midl + 1;
          } else {
            lr = midl - 1;
          }
          if (nums[midr] > target) {
            r = midr - 1;
          } else {
            rl = midr + 1;
          }
        }
        break;
      }
    }
    if (l <= r) ans[0] = l, ans[1] = r;

    return ans;
  }
};

int main() {
  Solution solution{};
  vector<int> nums{5,7,7,8,8,10};
  vector<int> ans = solution.searchRange(nums, 8);
//  cout << ans << endl;
  return 0;
}

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
  int minimumIncompatibility(vector<int>& nums, int k) {
    int n = nums.size(), sz = n / k;
    vector<int> ss(10, 0);
    for(int i = 0; i < n; i++) ss[nums[i]]++;
    int i = 0, ans = 0, cc = 0, l = 0;
    while(i < 10 && k){
      if (ss[i]) {
        ss[i]--;
        cc++;
        if (cc == 1) l = i;
        if (cc == sz) {
          ans += i - l;
          i = 0;
          cc = 0;
          k--;
        } else
          i++;
      } else i++;
      if (i == 10 && cc < sz) return -1;
    }
    return ans;
  }
};

int main() {
  Solution solution{};
  vector<int> nums{6,3,8,1,3,1,2,2};
  int ans = solution.minimumIncompatibility(nums, 4);
  cout << ans << endl;
  return 0;
}

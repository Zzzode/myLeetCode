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

int main() {
  Solution solution{};
  vector<int> nums{1, -5, -20, 4, -1, 3, -6, -3};
  int ans = solution.maxResult(nums, 2);
  cout << ans << endl;
  return 0;
}

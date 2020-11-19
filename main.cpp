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
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size(), sum = 0, ans = -1;
    v1<int> sp, st;
    for (int i = 0; i < n; i++) {
      sp.eb(gas[i] - cost[i]);
      sum += sp[i];
      if (sp[i] >= 0) st.eb(i);
    }
    if (sum < 0) return ans;

    for (int i : st) {
      int j = i, s = 0;
      int k = gas.size();
      while (k && s >= 0) {
        s += sp[j];
        k--, j = (j + 1) % n;
      }
      if (s >= 0) {
        ans = i;
        break;
      }
    }

    return ans;
  }
};

int main() {
  Solution solution{};
  v1<int> gas{1, 2, 3, 4, 5};
  v1<int> cost{3, 4, 5, 1, 2};
  int ans = solution.canCompleteCircuit(gas, cost);
  cout << ans << endl;
  return 0;
}
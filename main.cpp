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
#include <stack>
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
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int ans = 0;

    vector<vector<int>> tmp;
    sort(dominoes.begin(), dominoes.end(), [](vector<int>& a, vector<int>& b) {
      if (a[0] > a[1]) swap(a[0], a[1]);
      if (b[0] > b[1]) swap(b[0], b[1]);
      return a[0] > a[1];
    });

    return ans;
  }
};

int main() {
  Solution solution{};
  vector<vector<int>> domins{{1, 2}, {2, 1}, {3, 4}, {5, 6}};
  int ans = solution.numEquivDominoPairs(domins);
  cout << ans << endl;
  return 0;
}

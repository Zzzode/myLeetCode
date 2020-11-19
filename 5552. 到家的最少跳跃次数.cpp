#include "Header.h"

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
  int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    uset<int> fbd{all(forbidden)};
    queue<v1<int>> q;
    q.emplace(3, 0);

    while (!q.empty()) {
      auto i = q.front();
      q.pop();
      if (i[0] == x) return i[1];

      int tr = i[0] + a, tl = i[0] - b;
      if (!fbd.count(tr) && tr <= 6000) {
        q.emplace(v1<int>{tr, i[1] + 1, 0});
        fbd.emplace(tr);
      }
      if (!i[2] && !fbd.count(tl) && tl >= 0) q.emplace(v1<int>{tl, i[1] + 1, 1});
    }

    return -1;
  }
};
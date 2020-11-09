#include "Header.h"

#define MOD 1000000007

using ull = unsigned long long;
template <typename T> using umset = unordered_multiset<T>;
template <typename T> using uset = unordered_set<T>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2>;
template <typename T> using v1 = vector<T>;
template <typename T> using v2 = vector<vector<T>>;
template <typename T1, typename T2> using p2 = pair<T1, T2>;

class Solution {
 public:
  int furthestBuilding(vector<int>& hei, int bricks, int ladders) {
    int n = hei.size();

    multiset<int> se;
    for (int i = 1; i < n; i++) {
      int h = hei[i] - hei[i - 1];
      if (h > 0) {
        if (ladders) {
          se.emplace(h);
          ladders--;
        } else {
          if (se.empty() || h <= *se.begin()) bricks -= h;
          else {
            bricks -= *se.begin();
            se.erase(se.begin());
            se.emplace(h);
          }

          if (bricks < 0) return i - 1;
        }
      }
    }

    return n - 1;
  }
};

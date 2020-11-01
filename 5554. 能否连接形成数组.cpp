#include "Header.h"

#define MOD 1000000007

using ull = unsigned long long;
template <typename T> using umset = unordered_multiset<T>;
template <typename T> using uset = unordered_set<T>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2>;
template <typename T> using v2 = vector<vector<T>>;
template <typename T> using v1 = vector<T>;

class Solution {
 public:
  bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    umap<int, int> h;
    int la = arr.size(), na = pieces.size();
    for (int i = 0; i < la; i++) h[arr[i]] = i;
    for (int i = 0; i < na; i++) {
      int tmp = pieces[i][0];
      if (!h.count(tmp)) return false;
      for (int j = 1; j < pieces[i].size(); j++) {
        if (!h.count(pieces[i][j]) || pieces[i][j] != arr[h[tmp] + 1])
          return false;
        tmp = pieces[i][j];
      }
    }
    return true;
  }
};
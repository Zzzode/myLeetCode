#include "Header.h"

template <typename T> using uset = unordered_set<T>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2>;
class Solution {
 public:
  bool canDistribute(vector<int>& nums, vector<int>& quantity) {
    int nn = nums.size(), nq = quantity.size();
    umap<int, vector<int>> ma;
    umap<int, int> hash;
    for (int i = 0; i < nn; i++) hash[nums[i]]++;
    for (auto& h : hash) ma[h.second].emplace_back(h.first);
    for (int i = 0; i < nq; i++) {
      if (ma.count(quantity[i])) ma
    }
  }
};

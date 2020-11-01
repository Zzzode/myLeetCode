#include "Header.h"

class Solution {
 public:
  vector<int> frequencySort(vector<int>& nums) {
    int len = nums.size();
    vector<int> ans;
    unordered_map<int, int> hash;
    map<int, set<int>> h1;
    for (int i = 0; i < len; i++) hash[nums[i]]++;
    for (auto& h : hash) h1[h.second].insert(h.first);
    for (auto& h : h1) {
      if (h.second.size() == 1)
        for (int i = 0; i < h.first; i++) ans.emplace_back(*h.second.begin());
      else {
        set<int>::reverse_iterator iter = h.second.rbegin();
        while (iter != h.second.rend()) {
          for (int i = 0; i < h.first; i++) ans.emplace_back(*iter);
          ++iter;
        }
      }
    }

    return ans;
  }
};

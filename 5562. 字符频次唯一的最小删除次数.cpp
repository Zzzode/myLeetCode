#include "Header.h"

#define rall(x) (x).rbegin(), (x).rend()
class Solution {
 public:
  int minDeletions(string s) {
    int len = s.length(), ans = 0;
    unordered_map<char, int> hash;
    vector<int> count;
    for (int i = 0; i < len; i++) hash[s[i]]++;
    for (auto& h : hash) count.emplace_back(h.second);
    sort(rall(count));
    for (int i = 1; i < count.size(); i++) {
      if (count[i] >= count[i - 1]) {
        if (!count[i - 1]) {
          ans += count[i];
          count[i] = 0;
        } else {
          ans += count[i] - count[i - 1] + 1;
          count[i] = count[i - 1] - 1;
        }
      }
    }
    return ans;
  }
};

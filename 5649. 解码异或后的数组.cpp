#include "Header.h"

class Solution {
public:
  vector<int> decode(vector<int>& encoded, int first) {
    vector<int> ans;
    ans.emplace_back(first);
    for (int i = 0; i < encoded.size(); i++) {
      ans.emplace_back(first ^ encoded[i]);
      first = ans.back();
    }

    return ans;
  }
};

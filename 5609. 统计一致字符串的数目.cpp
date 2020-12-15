#include "Header.h"

class Solution {
public:
  int countConsistentStrings(string allowed, vector<string>& words) {
    int ans = 0;
    set<char> as{allowed.begin(), allowed.end()};
    for (int i = 0; i < words.size(); i++) {
      bool flag = true;
      for (int j = 0; j < words[i].size(); j++) {
        if (!as.count(words[i][j])) {
          flag = false;
          break;
        }
      }
      if (flag) ans++;
    }
    return ans;
  }
};

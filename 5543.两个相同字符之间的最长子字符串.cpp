#include "Header.h"

class Solution {
 public:
  int maxLengthBetweenEqualCharacters(string s) {
    int ans = -1;
    int len = s.length();
    for (int l = 0; l < len / 2; l++)
      for (int r = len - 1; r > l; r--)
        if (s[l] == s[r]) ans = max(r - l - 1, ans);

    return ans;
  }
};

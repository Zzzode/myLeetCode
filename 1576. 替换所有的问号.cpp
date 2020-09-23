#include "Header.h"

class Solution {
public:
  string modifyString(string s) {
    for (int i = 0; i < s.length(); i++) {
      s[i] = s[i] == '?' ? 'a' : s[i];
      if (i > 0 && i < s.length() - 1) {
        while (s[i] == s[i - 1] || s[i] == s[i + 1])
          s[i] += (s[i] - 'a' + 1) % 26;
      } else if (i == 0) {
        if (s[i + 1] == s[i])
          s[i]++;
      } else {
        if (s[i - 1] == s[i])
          s[i]++;
      }
    }
    return s;
  }
};

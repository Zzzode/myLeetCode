#include "Header.h"

class Solution {
 public:
  int maxRepeating(string sequence, string word) {
    int ls = sequence.size(), lw = word.size();
    if (sequence.find(word) == string::npos) return 0;
    int i = 1;
    int ans = 1;
    string tmp = word;
    while (i * lw <= ls) {
      if (sequence.find(tmp) != string::npos) ans = i;
      tmp += word;
      i++;
    }

    return ans;
  }
};

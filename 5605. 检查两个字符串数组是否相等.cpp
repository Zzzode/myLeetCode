#include "Header.h"

class Solution {
 public:
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string w1, w2;
    for (auto w : word1) w1 += w;
    for (auto w : word2) w2 += w;
    if (w1 == w2) return true;
    else
      return false;
  }
};

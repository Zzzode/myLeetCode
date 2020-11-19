#include "Header.h"

class Solution {
 public:
  bool closeStrings(string word1, string word2) {
    int l1 = word1.size(), l2 = word2.size();
    if (l1 != l2) return false;

    vector<int> c1(26, 0), c2(26, 0);
    for (int i = 0; i < l1; i++) {
      c1[word1[i] - 'a']++;
      c2[word2[i] - 'a']++;
    }

    multiset<int> cc1;
    multiset<int> cc2;
    for (int i = 0; i < 26; i++) {
      if (c1[i] && !c2[i]) return false;
      if (c1[i] == c2[i]) c1[i] = c2[i] = 0;
      else {
        cc1.emplace(c1[i]);
        cc2.emplace(c2[i]);
      }
    }
    if (cc1.size() != cc2.size()) return false;

    for (auto& m : cc1)
      if (!cc2.count(m)) return false;

    return true;
  }
};

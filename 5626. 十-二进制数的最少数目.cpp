#include "Header.h"

class Solution {
public:
  int minPartitions(string n) {
    int len = n.length(), ans = 0;
    sort(n.rbegin(), n.rend());
    while (!n.empty()) {
      int c = n.back() - '0';
      ans += c;
      if (c)
        for (int i = 0; i < n.size(); i++) n[i] -= c;
      while (!n.empty() && n.back() == '0') n.pop_back();
    }

    return ans;
  }
};

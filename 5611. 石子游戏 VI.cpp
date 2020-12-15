#include "Header.h"

class Solution {
public:
  int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
    int n = aliceValues.size();
    vector<int> s(n);
    for (int i = 0; i < n; i += 1) s[i] = aliceValues[i] + bobValues[i];
    sort(s.begin(), s.end(), greater<int>());
    int A = 0, B = 0;
    for (int x : aliceValues) A += x;
    for (int x : bobValues) B += x;
    for (int i = 0; i < n; i += 1)
      if (i & 1) B += s[i];
      else
        A += s[i];
    if (A > B) return 1;
    if (A < B) return -1;
    return 0;
  }
};

#include "Header.h"

class Solution {
 public:
  string getSmallestString(int n, int k) {
    string ans(n, 'a');
    k -= n;
    int i = n - 1;
    while (k) {
      if (k >= 25) {
        ans[i] += 25;
        k -= 25;
      } else {
        ans[i] += k;
        k = 0;
      }
      i--;
    }

    return ans;
  }
};

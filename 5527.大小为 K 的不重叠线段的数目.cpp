#include "Header.h"

#define MOD 1000000007

class Solution {
 public:
  int numberOfSets(int n, int k) {
    int ans = 0;
    for (int i = n - 1; i >= k; i--) ans += c(k, i);
    return ans % MOD;
  }

  int c(int n, int m) {
    return fact(m) / (fact(n) * fact(m - n));
  }

  int fact(int n) {
    int i, f = 1;
    for (i = 1; i <= n; ++i) f = f * i;
    return f;
  }
};

#include "Header.h"

class Solution {
public:
  int totalMoney(int n) {
    int res = n % 7, count = n / 7;
    int ans = 28 * count + count * (count - 1) / 2 * 7;
    ans += (2 * count + res + 1) * res / 2;

    return ans;
  }
};

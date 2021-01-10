#include "Header.h"

class Solution {
public:
  vector<int> constructDistancedSequence(int n) {
    vector<int> ans(2 * n - 1, 0);

    vector<int> v(n + 1, 0);
    int l = 0, r = l + n, tmp = n;
    while (tmp > 1) {
      ans[l] = ans[r] = tmp;
      l++, r--;
      tmp -= 2;
    }

    tmp = n;
    if (r - l == 3) {
      ans[l + 1] = ans[l + tmp] = tmp - 1;
      ans[l + 2] = ans[l + tmp - 1] = tmp - 3;
      tmp -= 3;
    } else {
      ans[l + 1] = ans[l + tmp] = tmp - 1;
      tmp -= 1;
    }

    l = n + 1;
    while (ans[l] && l < ans.size() - 1) l++;

    tmp -= 2;
    while (tmp) {}

    return ans;
  }
};

#include "Header.h"

#define MOD 1000000007
// #define all(x) (x).begin(), (x).end()
using ll = long long;
class Solution {
 public:
  int maxProfit(vector<int>& inventory, int orders) {
    ll ans = 0;
    int n = inventory.size();
    sort(inventory.rbegin(), inventory.rend());

    int i = 0;
    while (i < n - 1) {
      ll delta = inventory[i] - inventory[i + 1];
      if (orders - delta * (i + 1) >= 0) {
        orders -= delta * (i + 1);
        ans += (inventory[i] + inventory[i + 1] + 1) * delta / 2 * (i + 1);
        i++;
      } else
        break;
    }

    ll max = inventory[i], nn = orders / (i + 1);
    ans += (2 * max - nn + 1) * nn / 2 * (i + 1);
    ans += (max - nn) * (orders % (i + 1));

    return ans % MOD;
  }
};

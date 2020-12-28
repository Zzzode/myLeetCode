#include <algorithm>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
  int maxCoins(vector<int>& piles) {
    int res = 0, size = piles.size() / 3;
    int i = 0, j = piles.size() - 1;
    sort(piles.begin(), piles.end());

    for (int k = 0; k < size; k++) {
      j--;
      res += piles[j--];
    }

    return res;
  }
};
// @lc code=end

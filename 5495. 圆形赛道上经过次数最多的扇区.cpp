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
  vector<int> mostVisited(int n, vector<int>& rounds) {
    vector<int> help(n, 0);
    int         size = rounds.size();
    help[rounds[0] - 1]++;

    for (int i = 0; i < size - 1; i++) {
      int s = rounds[i + 1] > rounds[i] ? rounds[i + 1] - rounds[i] :
                                          n - rounds[i] + rounds[i + 1];
      // cout << s << " ";
      for (int j = 0; j < s; j++) {
        cout << (rounds[i] + j) % n << " ";
        help[(rounds[i] + j) % n]++;
      }
    }
    cout << endl;
    int max = 0;
    for (auto h : help) {
      cout << h << " ";
      max = std::max(max, h);
    }

    vector<int> res;

    for (int i = 0; i < help.size(); i++) {
      if (help[i] == max)
        res.push_back(i + 1);
    }

    return res;
  }
};
// @lc code=end

#include "Header.h"

class Solution {
 public:
  int minimumDeletions(string s) {
    int len = s.length();
    int ans = INT32_MAX;
    if (len == 1) return 0;

    vector<pair<int, int>> count(len, {0, 0});
    count[0] = pair<int, int>{s[0] == 'a', s[0] == 'b'};
    for (int i = 1; i < len; i++) {
      count[i].first = count[i - 1].first + (s[i] == 'a');
      count[i].second = count[i - 1].second + (s[i] == 'b');
    }

    for (int i = 0; i < len; i++) {
      int da = i > 0 ? count[i - 1].second : 0;
      int db = i > 0 ? count[len - 1].first - count[i - 1].first :
                       count[len - 1].first;
      ans = min(da + db, ans);
    }
    ans = min({ans, count[len - 1].first, count[len - 1].second});

    return ans;
  }
};

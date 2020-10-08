#include "Header.h"

class Solution {
public:
  int minOperations(vector<string>& logs) {
    int ans = 0;
    for (auto log : logs) {
      if (log == "../")
        ans = ans > 0 ? ans - 1 : 0;
      else if (log == "./")
        ans = ans;
      else
        ans++;
    }
    return ans;
  }
};

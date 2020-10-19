#include "Header.h"

using PII = pair<int, int>;
class Solution {
 public:
  int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    vector<PII> v;
    int len = scores.size();
    for (int i = 0; i < len; i++) v.emplace_back(scores[i], ages[i]);
    sort(v.begin(), v.end());

    return 0;
  }
};

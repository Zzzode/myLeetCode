#include "Header.h"

using pii = pair<int, int>;

class Solution {
 public:
  vector<bool>
  checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    vector<pii> v;
    for (int i = 0; i < l.size(); i++) v.emplace_back(l[i], r[i]);
    // for (auto& h : v) cout << h.first << " " << h.second << endl;

    vector<bool> ans;
    for (auto& h : v) {
      if (h.second == h.first) ans.emplace_back(true);
      else if (h.second < h.first)
        ans.emplace_back(false);
      else {
        vector<int> tmp{nums.begin() + h.first, nums.begin() + h.second + 1};
        // copy(nums.begin() + h.first, nums.begin() + h.second, tmp);
        for (auto t : tmp) cout << t << " ";
        cout << endl;
        sort(tmp.begin(), tmp.end());
        int n = tmp[1] - tmp[0];
        bool b = true;
        for (int i = 1; i < tmp.size(); i++) {
          if (tmp[i] - tmp[i - 1] != n) {
            b = false;
            break;
          }
        }
        ans.emplace_back(b);
      }
    }

    return ans;
  }
};

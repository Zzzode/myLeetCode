#include "Header.h"

class Solution {
 public:
  vector<int> partitionLabels(string S) {
    unordered_map<char, vector<int>> h;
    vector<int> ans;
    int len = S.length();
    if (len == 1) return {1};

    for (int i = 0; i < len; i++) h[S[i]].emplace_back(i);

    for (int i = 0; i < len; ++i) {
      if (h[S[i]].size() == 1) ans.emplace_back(1);
      else {
        int r = h[S[i]].back();
        for (int j = i; j <= r; j++) { r = max(r, h[S[j]].back()); }
        ans.emplace_back(r - i + 1);
        i = r;
      }
    }

    return ans;
  }
};

int main() {
  Solution solution;
  string in;
  cin >> in;
  vector<int> ans;
  ans = solution.partitionLabels(in);
  for (auto& a : ans) cout << a << " ";

  return 0;
}
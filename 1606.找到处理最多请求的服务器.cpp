#include "Header.h"

using PII = pair<int, int>;
class Solution {
 private:
  int max;
  vector<int> ss;
  set<int> em;

 private:
  set<PII> hash;

 public:
  void init(int& k) {
    max = 0;
    ss.resize(k, 0);
    for (int i = 0; i < k; i++) em.emplace(i);
  }

  vector<int> busiestServers(int k, vector<int>& arr, vector<int>& load) {
    init(k);

    int len = arr.size();
    for (int i = 0; i < len; i++) {
      updateServer(i, arr);
      setServer(i, k, arr, load);
    }

    vector<int> ans;
    for (int i = 0; i < ss.size(); i++)
      if (ss[i] == max) ans.emplace_back(i);

    return ans;
  }

  void updateServer(int& i, vector<int>& arr) {
    for (auto& h : hash) {
      if (h.first <= arr[i]) {
        em.emplace(h.second);
        hash.erase(h);
      } else
        break;
    }
  }

  void setServer(int& i, int& k, vector<int>& arr, vector<int>& load) {
    int j = selectServer(i, k);
    if (j != -1) {
      em.erase(j);
      hash.emplace(arr[i] + load[i], j);
      ss[j]++;
      max = std::max(ss[j], max);
    }
  }

  int selectServer(int& i, int n) {
    int j = i % n;
    if (!em.empty()) {
      auto it = em.lower_bound(j);
      if (it == em.end()) return *em.begin();
      else
        return *it;
    }

    return -1;
  }
};

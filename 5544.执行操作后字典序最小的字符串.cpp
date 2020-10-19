#include "Header.h"

class Solution {
  set<string> hash;

 public:
  string findLexSmallestString(string s, int a, int b) {
    int n = s.length();
    dfs(s, a, b, n);
    return *hash.begin();
  }

  void dfs(string s, int& a, int& b, int& n) {
    if (hash.count(s)) return;
    hash.insert(s);

    dfs(plus(s, a, n), a, b, n);
    dfs(shift(s, b, n), a, b, n);
  }

  string plus(string& s, int& a, int& n) {
    string res(s);
    for (int i = 1; i < n; i += 2) res[i] = '0' + (s[i] - '0' + a) % 10;
    return res;
  }

  string shift(string& s, int& b, int& n) {
    string res;
    res = s.substr(n - b, b) + s.substr(0, n - b);
    return res;
  }
};

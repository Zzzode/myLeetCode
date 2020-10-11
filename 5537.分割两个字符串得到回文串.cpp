#include "Header.h"

class Solution {
 public:
  bool checkPalindromeFormation(string a, string b) {
    return check(a, b) || check(b, a);
  }

  bool check(string& a, string& b) {
    int len = a.length();
    for (int i = 0, j = len - 1; i < j; i++, j--)
      if (a[i] != b[j]) return check1(a, i, j) || check1(b, i, j);

    return true;
  }

  bool check1(string& s, int l, int r) {
    for (int i = l, j = r; i < j; i++, j--)
      if (s[i] != s[j]) return false;
    return true;
  }
};

//超时解法
class Solution2 {
 public:
  bool checkPalindromeFormation(string a, string b) {
    int len = a.length();
    for (int i = 0; i <= len; i++) {
      string ap(a.substr(0, i)), as;
      string bp(b.substr(0, i)), bs;
      if (i < len) {
        as = a.substr(i, len - i);
        bs = b.substr(i, len - i);
      }
      string apbs = ap + bs;
      string bpas = bp + as;
      // cout << apbs << " " << bpas << endl;
      bool t1 = true, t2 = true;
      for (int j = 0; j < apbs.length() / 2; j++) {
        if (apbs[j] != apbs[apbs.length() - j - 1]) {
          t1 = false;
          break;
        }
      }
      for (int j = 0; j < bpas.length() / 2; j++) {
        if (bpas[j] != bpas[bpas.length() - j - 1]) {
          t2 = false;
          break;
        }
      }
      if (t1 || t2) return true;
    }
    return false;
  }
};

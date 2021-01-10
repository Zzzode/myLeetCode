#include "Header.h"

class Solution {
public:
  int maximumGain(string s, int x, int y) {
    int len = s.length(), ans = 0;
    vector<char> v;

    for (int i = 0; i < len; i++) {
      if (s[i] == 'a' + (x >= y)) {
        if (!v.empty() && v.back() == 'a' + (x < y)) {
          ans += max(x, y);
          v.pop_back();
        } else {
          v.push_back(s[i]);
        }
      } else if (s[i] == 'a' + (x < y)) {
        v.push_back(s[i]);
      } else {
        if (!v.empty()) {
          stack<char> st;
          st.push(v[0]);
          for (int j = 1; j < v.size(); j++) {
            if (st.empty()) st.push(v[j]);
            else {
              if (v[j] != st.top()) {
                ans += v[j] == 'a' ? y : x;
                st.pop();
              } else
                st.push(v[j]);
            }
          }
          v.clear();
        }
      }
    }

    if (!v.empty()) {
      stack<char> st;
      st.push(v[0]);
      for (int j = 1; j < v.size(); j++) {
        if (st.empty()) st.push(v[j]);
        else {
          if (v[j] != st.top()) {
            ans += v[j] == 'a' ? y : x;
            st.pop();
          } else
            st.push(v[j]);
        }
      }
      v.clear();
    }

    return ans;
  }
};

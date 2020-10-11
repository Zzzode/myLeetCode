#include "Header.h"

class Solution {
 public:
  int maxDepth(string s) {
    int ans = 0;
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(') st.push(s[i]);
      if (s[i] == ')') {
        ans = max(ans, (int)st.size());
        st.pop();
      }
    }
    return ans;
  }
};

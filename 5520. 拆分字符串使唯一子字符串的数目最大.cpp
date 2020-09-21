/*
 * 给你一个字符串s，请你拆分该字符串，并返回拆分后唯一子字符串的最大数目。
 * 字符串s拆分后可以得到若干非空子字符串，这些子字符串连接后应当能够还原为原字符串。
 * 但是拆分出来的每个子字符串都必须是唯一的。
 * 注意：子字符串 是字符串中的一个连续字符序列。
 */

#include "Header.h"

class Solution {
public:
  int maxUniqueSplit(string s) {
    int ans = 0;
    int len = s.length();
    unordered_set<string> res;
    function<void(int)> dfs = [&](int pos) {
      // visit this
      if (pos == len) {
        ans = max(ans, (int)res.size());
        return;
      }

      // dfs
      string tmp;
      for (int i = pos; i < len; i++) {
        tmp += s[i];
        if (res.find(tmp) == res.end()) {
          res.insert(tmp);
          dfs(i + 1);
          res.erase(tmp);
        }
      }
    };
    dfs(0);

    return ans;
  }
};

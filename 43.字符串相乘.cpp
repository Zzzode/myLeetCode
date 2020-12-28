/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
  string multiply(string num1, string num2) {
    int len1 = num1.length();
    int len2 = num2.length();
    int back = len1 + len2 - 1;

    vector<char> str(len1 + len2, 'e');

    for (int i = len1 - 1; i >= 0; i--) {
      int co = 0;

      for (int j = len2 - 1; j >= 0; j--) {
        char tmp = str[back - (len2 - j - 1)];

        int product = (num1[i] - '0') * (num2[j] - '0');
        int res     = tmp == 'e' ? product + co : product + co + tmp - '0';

        str[back - (len2 - j - 1)] = res % 10 + '0';
        co                         = res / 10;

        if (j == 0 && co > 0)
          str[back - (len2 - j)] = co + '0';
      }
      back--;
    }

    string ans;
    bool   front = false;
    for (int i = 0; i < str.size(); i++) {
      if (!front) {
        if (str[i] == 'e' || str[i] == '0' && i != str.size() - 1)
          continue;
        else {
          front = true;
          ans += str[i];
        }
      } else
        ans += str[i];
    }

    return ans;
  }
};
// @lc code=end

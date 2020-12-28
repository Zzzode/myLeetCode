/*
 * @lc app=leetcode.cn id=468 lang=cpp
 *
 * [468] 验证IP地址
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<string> split(const string& str, const string& seperator) {
    vector<string> res;
    int            begin = 0;
    int            pos   = str.find(seperator);

    while (pos != str.npos) {
      res.push_back(str.substr(begin, pos - begin));
      begin = pos + seperator.size();
      pos   = str.find(seperator, begin);
    }
    res.push_back(str.substr(begin));

    return res;
  }

  string validIPAddress(string IP) {
    string res("Neither");
    int    begin = 0;

    vector<string> subsDot = split(IP, ".");
    vector<string> subsCol = split(IP, ":");

    if (subsDot.size() == 4) {
      for (auto sub : subsDot) {
        int count = 0;
        int num   = 0;
        if (sub.empty())
          return "Neither";

        try {
          num = stoi(sub, nullptr, 10);
        } catch (std::invalid_argument) {
          return "Neither";
        } catch (std::out_of_range) { return "Neither"; }

        if (num < 0 || num > 255)
          return "Neither";

        do {
          num /= 10;
          count++;
        } while (num != 0);

        if (count != sub.size())
          return "Neither";
        else
          res = "IPv4";
      }
    } else if (subsCol.size() == 8) {
      for (auto sub : subsCol) {
        if (sub.empty() || sub.size() > 4)
          return "Neither";

        for (auto a : sub) {
          if (!(isdigit(a) || (a >= 'a' && a <= 'f') || (a >= 'A' && a <= 'F')))
            return "Neither";
        }

        res = "IPv6";
      }
    }

    return res;
  }
};
// @lc code=end

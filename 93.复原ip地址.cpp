/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */
#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
  vector<string> res;
  vector<string> restoreIpAddresses(string s) {
    int n = s.size();
    string cur = s;
    helper(n, 0, -1, cur, s);
    return res;
  }
  void helper(int n, int pointnum, int lastpoint, string &cur, string &s) {
    // pointnum记录目前加了几个点了，lastpoint记录上一个点加的位置
    if (pointnum == 3) {
      //如果已经加了三个点了，并且最后一个点的右边表示的数小于255，则是正确IP地址
      if (valid(lastpoint + 1, n - 1, s)) {
        res.push_back(cur);
      }
      return;
    }
    //从上一个.号的下一个位置开始查找
    for (int i = lastpoint + 1; i < n - 1; i++) {
      //如果字符串s从上一个.号到i位置表示的数小于等于255，则符合条件
      if (valid(lastpoint + 1, i, s)) {
        //正常回溯法，注意这里要+pointnum，因为已经加入的.号也会占位
        cur.insert(cur.begin() + i + pointnum + 1, '.');
        helper(n, pointnum + 1, i, cur, s);
        cur.erase(pointnum + i + 1, 1);
      }
    }
    return;
  }
  bool valid(int left, int right, string &s) {
    int sum = 0;
    for (int i = left; i <= right; i++) {
      //处理0开头问题
      if (left != right and s[left] == '0')
        return false;
      //计算字符串s中left到right位表示的数的大小
      sum = sum * 10 + (s[i] - '0');
      if (sum > 255)
        return false;
    }
    return true;
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1512 lang=cpp
 *
 * [1512] 好数对的数目
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
  int numIdenticalPairs(vector<int> &nums) {
    int res = 0;
    unordered_map<int, int> help;

    for (auto num : nums)
      help[num]++;
    for (auto h : help)
      if (h.second > 1)
        res += h.second * (h.second - 1) / 2;

    return res;
  }
};
// @lc code=end

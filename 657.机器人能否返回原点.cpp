/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */
#include <algorithm>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
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
  bool judgeCircle(string moves) {
    int x = 0, y = 0;

    for (auto move : moves) {
      switch (move) {
        case 'U': y++; break;
        case 'D': y--; break;
        case 'L': x--; break;
        case 'R': x++; break;
        default: break;
      }
    }

    return x == 0 && y == 0;
  }
};
// @lc code=end

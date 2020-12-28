/*
 * @lc app=leetcode.cn id=546 lang=cpp
 *
 * [546] 移除盒子
 */
#include <algorithm>
#include <cmath>
#include <cstring>
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
  int dp[100][100][100];

  int removeBoxes(vector<int> &boxes) {
    memset(dp, 0, sizeof dp);
    return calculatePoints(boxes, 0, boxes.size() - 1, 0);
  }

  int calculatePoints(vector<int> &boxes, int l, int r, int k) {
    if (l > r)
      return 0;
    if (dp[l][r][k] != 0)
      return dp[l][r][k];
    while (r > l && boxes[r] == boxes[r - 1]) {
      r--;
      k++;
    }
    dp[l][r][k] = calculatePoints(boxes, l, r - 1, 0) + (k + 1) * (k + 1);
    for (int i = l; i < r; i++) {
      if (boxes[i] == boxes[r]) {
        dp[l][r][k] =
            max(dp[l][r][k], calculatePoints(boxes, l, i, k + 1) +
                                 calculatePoints(boxes, i + 1, r - 1, 0));
      }
    }
    return dp[l][r][k];
  }
};
// @lc code=end

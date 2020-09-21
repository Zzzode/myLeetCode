/*
 * 给你一个大小为 rows x cols 的矩阵 grid 。
 * 最初，你位于左上角 (0, 0) ，每一步，你可以在矩阵中 向右 或 向下 移动。
 * 在从左上角 (0, 0) 开始到右下角 (rows - 1, cols - 1) 结束的所有路径中，
 * 找出具有 最大非负积 的路径。路径的积是沿路径访问的单元格中所有整数的乘积。
 * 返回 最大非负积 对 109 + 7 取余 的结果。如果最大积为负数，则返回 -1 。
 * 注意，取余是在得到最大积之后执行的。
 */

#include "Header.h"

#define MOD 1000000007
using LL = long long;

class Solution {
public:
  int maxProductPath(vector<vector<int>>& grid) {
    int len = grid[0].size(), height = grid.size();

    vector<vector<pair<LL, LL>>> dp(height, vector<pair<LL, LL>>(len));
    dp[0][0].first = dp[0][0].second = grid[0][0];

    for (int i = 1; i < len; ++i)
      dp[0][i].first = dp[0][i].second = dp[0][i - 1].first * grid[0][i];
    for (int i = 1; i < height; ++i)
      dp[i][0].first = dp[i][0].second = dp[i - 1][0].first * grid[i][0];

    for (int i = 1; i < height; ++i) {
      for (int j = 1; j < len; ++j) {
        if (grid[i][j] > 0) {
          dp[i][j].first =
              min(dp[i - 1][j].first, dp[i][j - 1].first) * grid[i][j];
          dp[i][j].second =
              max(dp[i - 1][j].second, dp[i][j - 1].second) * grid[i][j];
        } else if (grid[i][j] < 0) {
          dp[i][j].second =
              min(dp[i - 1][j].first, dp[i][j - 1].first) * grid[i][j];
          dp[i][j].first =
              max(dp[i - 1][j].second, dp[i][j - 1].second) * grid[i][j];
        }
      }
    }

    if (dp[height - 1][len - 1].second < 0)
      return -1;

    return dp[height - 1][len - 1].second % MOD;
  }
};

/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 *
 * https://leetcode-cn.com/problems/island-perimeter/description/
 *
 * algorithms
 * Easy (68.19%)
 * Likes:    265
 * Dislikes: 0
 * Total Accepted:    25.7K
 * Total Submissions: 37.5K
 * Testcase Example:  '[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]'
 *
 * 给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。
 *
 * 网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
 *
 * 岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1
 * 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。
 *
 *
 *
 * 示例 :
 *
 * 输入:
 * [[0,1,0,0],
 * ⁠[1,1,1,0],
 * ⁠[0,1,0,0],
 * ⁠[1,1,0,0]]
 *
 * 输出: 16
 *
 * 解释: 它的周长是下面图片中的 16 个黄色的边：
 *
 *
 *
 *
 */
#include "Header.h"
// @lc code=start
#define fi first
#define se second
template <typename T> using v2 = vector<vector<T>>;
using pii = pair<int, int>;

class Solution {
 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int ans = 0;
    int l = grid[0].size(), h = grid.size();

    v2<bool> v(h, vector<bool>(l, false));

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < l; j++)
        if (grid[i][j] && !v[i][j]) ans += bfs(grid, v, i, j, h, l);
    }

    return ans;
  }

  int bfs(v2<int>& g, v2<bool>& v, int i, int j, int& hei, int& len) {
    int sum = 0;
    queue<pii> q;
    q.emplace(i, j);
    v[i][j] = true;

    while (!q.empty()) {
      auto h = q.front();
      int c = 4;
      q.pop();

      if (h.fi > 0 && g[h.fi - 1][h.se]) {
        c--;
        if (!v[h.fi - 1][h.se]) {
          q.emplace(h.fi - 1, h.se);
          v[h.fi - 1][h.se] = true;
        }
      }
      if (h.fi < hei - 1 && g[h.fi + 1][h.se]) {
        c--;
        if (!v[h.fi + 1][h.se]) {
          q.emplace(h.fi + 1, h.se);
          v[h.fi + 1][h.se] = true;
        }
      }
      if (h.se > 0 && g[h.fi][h.se - 1]) {
        c--;
        if (!v[h.fi][h.se - 1]) {
          q.emplace(h.fi, h.se - 1);
          v[h.fi][h.se - 1] = true;
        }
      }
      if (h.se < len - 1 && g[h.fi][h.se + 1]) {
        c--;
        if (!v[h.fi][h.se + 1]) {
          q.emplace(h.fi, h.se + 1);
          v[h.fi][h.se + 1] = true;
        }
      }

      sum += c;
    }

    return sum;
  }
};
// @lc code=end

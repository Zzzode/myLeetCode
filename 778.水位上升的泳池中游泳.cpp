/*
 * @lc app=leetcode.cn id=778 lang=cpp
 *
 * [778] 水位上升的泳池中游泳
 *
 * https://leetcode-cn.com/problems/swim-in-rising-water/description/
 *
 * algorithms
 * Hard (47.59%)
 * Likes:    140
 * Dislikes: 0
 * Total Accepted:    15.4K
 * Total Submissions: 26.2K
 * Testcase Example:  '[[0,2],[1,3]]'
 *
 * 在一个 N x N 的坐标方格 grid 中，每一个方格的值 grid[i][j] 表示在位置 (i,j)
 * 的平台高度。
 *
 * 现在开始下雨了。当时间为 t 时，此时雨水导致水池中任意位置的水位为 t
 * 。你可以从一个平台游向四周相邻的任意一个平台，但是前提是此时水位必须同时淹没这两个平台。假定你可以瞬间移动无限距离，也就是默认在方格内部游动是不耗时的。当然，在你游泳的时候你必须待在坐标方格里面。
 *
 * 你从坐标方格的左上平台 (0，0)
 * 出发。最少耗时多久你才能到达坐标方格的右下平台 (N-1, N-1)？
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: [[0,2],[1,3]]
 * 输出: 3
 * 解释:
 * 时间为0时，你位于坐标方格的位置为 (0, 0)。
 * 此时你不能游向任意方向，因为四个相邻方向平台的高度都大于当前时间为 0
 * 时的水位。
 *
 * 等时间到达 3 时，你才可以游向平台 (1, 1). 因为此时的水位是
 * 3，坐标方格中的平台没有比水位 3 更高的，所以你可以游向坐标方格中的任意位置
 *
 *
 * 示例2:
 *
 *
 * 输入:
 * [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
 * 输出: 16
 * 解释:
 * ⁠0  1  2  3  4
 * 24 23 22 21  5
 * 12 13 14 15 16
 * 11 17 18 19 20
 * 10  9  8  7  6
 *
 * 最终的路线用加粗进行了标记。
 * 我们必须等到时间为 16，此时才能保证平台 (0, 0) 和 (4, 4) 是连通的
 *
 *
 *
 *
 * 提示:
 *
 *
 * 2 .
 * grid[i][j] 是 [0, ..., N*N - 1] 的排列。
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
public:
  int find(vector<int>& f, int x) {
    if (f[x] == x) { return x; }
    int fa = find(f, f[x]);
    f[x] = fa;
    return fa;
  }

  void merge(vector<int>& f, int x, int y) {
    int fx = find(f, x), fy = find(f, y);
    f[fx] = fy;
  }

  int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> f(n * n);
    for (int i = 0; i < n * n; i++) { f[i] = i; }

    vector<pair<int, int>> idx(n * n);  // 存储每个平台高度对应的位置
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) { idx[grid[i][j]] = make_pair(i, j); }
    }

    vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (int threshold = 0; threshold < n * n; threshold++) {
      auto [i, j] = idx[threshold];
      for (const auto [di, dj] : directions) {
        int ni = i + di, nj = j + dj;
        if (ni >= 0 && ni < n && nj >= 0 && nj < n &&
            grid[ni][nj] <= threshold) {
          merge(f, i * n + j, ni * n + nj);
        }
      }
      if (find(f, 0) == find(f, n * n - 1)) { return threshold; }
    }
    return -1;  // cannot happen
  }
};
// @lc code=end

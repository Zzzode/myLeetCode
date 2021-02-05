/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 *
 * [1631] 最小体力消耗路径
 *
 * https://leetcode-cn.com/problems/path-with-minimum-effort/description/
 *
 * algorithms
 * Medium (33.80%)
 * Likes:    116
 * Dislikes: 0
 * Total Accepted:    10K
 * Total Submissions: 22.5K
 * Testcase Example:  '[[1,2,2],[3,8,2],[5,3,5]]'
 *
 * 你准备参加一场远足活动。给你一个二维 rows x
 * columns 的地图 heights ，其中 heights[row][col] 表示格子 (row,
 * col) 的高度。一开始你在最左上角的格子 (0,
 * 0) ，且你希望去最右下角的格子 (rows-1, columns-1) （注意下标从 0
 * 开始编号）。你每次可以往 上，下，左，右 四个方向之一移动，你想要找到耗费 体力
 * 最小的一条路径。
 *
 * 一条路径耗费的 体力值 是路径上相邻格子之间 高度差绝对值 的 最大值 决定的。
 *
 * 请你返回从左上角走到右下角的最小 体力消耗值 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：heights = [[1,2,2],[3,8,2],[5,3,5]]
 * 输出：2
 * 解释：路径 [1,3,5,3,5] 连续格子的差值绝对值最大为 2 。
 * 这条路径比路径 [1,2,2,2,5] 更优，因为另一条路径差值最大值为 3 。
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：heights = [[1,2,3],[3,8,4],[5,3,5]]
 * 输出：1
 * 解释：路径 [1,2,3,4,5] 的相邻格子差值绝对值最大为 1 ，比路径 [1,3,5,3,5]
 * 更优。
 *
 *
 * 示例 3：
 *
 *
 * 输入：heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
 * 输出：0
 * 解释：上图所示路径不需要消耗任何体力。
 *
 *
 *
 *
 * 提示：
 *
 *
 * rows == heights.length
 * columns == heights[i].length
 * 1
 * 1
 *
 *
 */
#include "Header.h"
// @lc code=start
class UnionFind {
private:
  vector<int> parent;
  vector<int> size;
  int n;
  int setCnt;

public:
  UnionFind(int _n) : n(_n), setCnt(_n), parent(_n), size(_n, 1) {
    iota(parent.begin(), parent.end(), 0);
  }

  int findset(int x) {
    return parent[x] == x ? x : parent[x] = findset(parent[x]);
  }

  bool unite(int x, int y) {
    x = findset(x);
    y = findset(y);

    if (x == y) return true;
    if (size[x] < size[y]) swap(x, y);

    parent[y] = x;
    size[x] += size[y];
    setCnt--;
    return true;
  }

  bool connected(int x, int y) {
    x = findset(x);
    y = findset(y);
    return x == y;
  }

  ~UnionFind() {}
};

class Solution {
private:
  struct Edges {
    int x, y;
    int height;
    bool operator<(const Edges& e) {
      return height < e.height;
    }
    Edges(int _x, int _y, int _h) : x(_x), y(_y), height(_h) {}
  };

public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    int rows = heights.size(), cols = heights[0].size();

    vector<Edges> v;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        int idx = i * cols + j;
        if (i)
          v.emplace_back(idx - cols, idx,
                         abs(heights[i][j] - heights[i - 1][j]));
        if (j)
          v.emplace_back(idx - 1, idx, abs(heights[i][j] - heights[i][j - 1]));
      }
    }

    sort(v.begin(), v.end());
    UnionFind uf(rows * cols);

    for (auto& e : v) {
      uf.unite(e.x, e.y);
      if (uf.connected(0, rows * cols - 1)) return e.height;
    }

    return 0;
  }
};
// @lc code=end

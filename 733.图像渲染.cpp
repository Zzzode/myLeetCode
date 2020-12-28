/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */
#include <algorithm>
#include <cmath>
#include <cstring>
#include <functional>
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
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int newColor) {
    int height = image.size();
    int length = image[0].size();
    int color = image[sr][sc];
    if (color == newColor)
      return image;
    vector<vector<bool>> visited(height, vector<bool>(length, false));

    function<void(int, int)> dfs = [&](int i, int j) {
      // visit p
      if (i < 0 || i >= height || j < 0 || j >= length || visited[i][j])
        return;
      visited[i][j] = true;
      if (image[i][j] != color)
        return;
      image[i][j] = newColor;

      dfs(i - 1, j);
      dfs(i, j - 1);
      dfs(i + 1, j);
      dfs(i, j + 1);
    };
    dfs(sr, sc);

    return image;
  }
};
// @lc code=end

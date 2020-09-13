/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
#include "Header.h"
// @lc code=start
class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
    int row = board.size();
    int col = board[0].size();

    vector<vector<bool>> visited(row, vector<bool>(col, false));
    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++)
        if (dfs(visited, board, word, i, j, 0))
          return true;

    return false;
  }

  inline bool dfs(vector<vector<bool>>& visited,
                  vector<vector<char>>& board,
                  string&               word,
                  int                   i,
                  int                   j,
                  int                   k) {
    if (i < 0 || i > board.size() - 1 || j < 0 || j > board[0].size() - 1)
      return false;
    if (visited[i][j] == true)
      return false;
    if (board[i][j] != word[k])
      return false;
    if (k == word.length() - 1)
      return true;
    visited[i][j] = true;

    if (dfs(visited, board, word, i + 1, j, k + 1) ||
        dfs(visited, board, word, i - 1, j, k + 1) ||
        dfs(visited, board, word, i, j + 1, k + 1) ||
        dfs(visited, board, word, i, j - 1, k + 1))
      return true;

    visited[i][j] = false;

    return false;
  };
};
// @lc code=end

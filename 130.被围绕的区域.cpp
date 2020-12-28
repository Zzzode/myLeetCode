/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
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
  Solution() : height(0), length(0) {}

  void solve(vector<vector<char>> &board) {
    if (board.empty())
      return;
    else {
      height = board.size();
      length = board.front().size();
      if (height == 2 || length == 2)
        return;
    }

    for (int i = 0; i < height; i++)
      for (int j = 0; j < length; j++)
        (i == 0 || i == height - 1)
            ? (board[i][j] == 'O' ? DFS(board, i, j) : 1)
            : ((j == 0 || j == length - 1)
                   ? (board[i][j] == 'O' ? DFS(board, i, j) : 1)
                   : 1);

    for (int i = 0; i < height; i++)
      for (int j = 0; j < length; j++)
        board[i][j] = board[i][j] == '1' ? 'O' : 'X';
  }

  int DFS(vector<vector<char>> &board, int y, int x) {
    // visit p;
    board[y][x] = '1';

    if (x + 1 < length)
      board[y][x + 1] == 'O' ? DFS(board, y, x + 1) : 1;
    if (x - 1 >= 0)
      board[y][x - 1] == 'O' ? DFS(board, y, x - 1) : 1;
    if (y + 1 < height)
      board[y + 1][x] == 'O' ? DFS(board, y + 1, x) : 1;
    if (y - 1 >= 0)
      board[y - 1][x] == 'O' ? DFS(board, y - 1, x) : 1;

    return 0;
  }

private:
  int height;
  int length;
};
// @lc code=end

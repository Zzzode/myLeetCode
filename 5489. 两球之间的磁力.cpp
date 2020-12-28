/*
 * @lc app=leetcode.cn id=5489 lang=cpp
 *
 * [5489] 两球之间的磁力
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
  int maxDistance(vector<int> &position, int m) {
    int l = 1e9, r = 0;
    sort(position.begin(), position.end());
    r = (position.back() - position.front()) / (m - 1);
    for (int i = 0; i < position.size() - 1; i++)
      l = min(position[i + 1] - position[i], l);

    while (l < r) {
      int count = 1;
      int mid = r - l == 1 ? r : (r + l) / 2;
      for (int i = 1, pre = 0; i < position.size(); i++) {
        if (position[i] - position[pre] >= mid) {
          count++;
          pre = i;
        }
      }
      if (count >= m)
        l = mid;
      else
        r = r - l == 1 ? r - 1 : mid;
    }

    return l;
  }
};
// @lc code=end

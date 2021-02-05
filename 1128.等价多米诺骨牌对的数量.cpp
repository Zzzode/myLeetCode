/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 *
 * https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs/description/
 *
 * algorithms
 * Easy (46.72%)
 * Likes:    84
 * Dislikes: 0
 * Total Accepted:    22.3K
 * Total Submissions: 41.7K
 * Testcase Example:  '[[1,2],[2,1],[3,4],[5,6]]'
 *
 * 给你一个由一些多米诺骨牌组成的列表 dominoes。
 *
 * 如果其中某一张多米诺骨牌可以通过旋转 0 度或 180
 * 度得到另一张多米诺骨牌，我们就认为这两张牌是等价的。
 *
 * 形式上，dominoes[i] = [a, b] 和 dominoes[j] = [c,
 * d] 等价的前提是 a==c 且 b==d，或是 a==d 且 b==c。
 *
 * 在 0 <= i < j < dominoes.length 的前提下，找出满足 dominoes[i]
 * 和 dominoes[j] 等价的骨牌对 (i, j) 的数量。
 *
 *
 *
 * 示例：
 *
 * 输入：dominoes = [[1,2],[2,1],[3,4],[5,6]]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= dominoes.length <= 40000
 * 1 <= dominoes[i][j] <= 9
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
public:
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int ans = 0;

    sort(dominoes.begin(), dominoes.end(), [](vector<int>& a, vector<int>& b) {
      if (a[0] > a[1]) swap(a[0], a[1]);
      if (b[0] > b[1]) swap(b[0], b[1]);
      return a[0] > a[1];
    });

    vector<vector<int>> tmp(10, vector<int>(10, 0));
    for (auto& domin : dominoes) { tmp[domin[0]][domin[1]]++; }
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) ans += tmp[i][j] * (tmp[i][j] - 1) / 2;
    }

    return ans;
  }
};
// @lc code=end

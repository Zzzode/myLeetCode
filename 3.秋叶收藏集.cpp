/*
 * 小扣出去秋游，途中收集了一些红叶和黄叶，他利用这些叶子初步整理了一份秋叶收藏leaves,
 * 字符串leaves仅包含小写字符r和y,其中字符r表示一片红叶，字符y表示一片黄叶。
 * 出于美观整齐的考虑，小扣想要将收藏集中树叶的排列调整成「红、黄、红」三部分。每部分树叶数量可以不相等，但均需大于等于
 * 1。每次调整操作，小扣可以将一片红叶替换成黄叶或者将一片黄叶替换成红叶。请问小扣最少需要多少次调整操作才能将秋叶收藏集调整完毕。
 *
 * 示例 1：
 * 输入：leaves = "rrryyyrryyyrr"
 * 输出：2
 * 解释：调整两次，将中间的两片红叶替换成黄叶，得到 "rrryyyyyyyyrr"
 *
 * 示例 2：
 * 输入：leaves = "ryr"
 * 输出：0
 * 解释：已符合要求，不需要额外操作
 *
 * 提示：
 * 3 <= leaves.length <= 10^5
 * leaves 中只包含字符 'r' 和字符 'y'
 *
 * 动态规划
 * 使用 3 个 dp 数组记录状态
 *
 * dp[0][i] 代表从头开始全部修改成红色（纯红）需要修改几次
 * dp[1][i] 代表从头开始是红色，然后现在是黄色（红黄），需要修改几次
 * dp[2][i] 代表从头开始是红色，然后变成黄色，又变成红色（红黄红），需要修改几次
 * 根据 i 是红是黄，判断转移情况

 * dp[0][i] 就很简单，如果是黄的，就比之前加一
 * dp[1][i] 可以从上一个纯红状态变化过来，也可以从上一个本身状态变化过来
 * dp[2][i] 可以从上一个红黄状态变化过来，也可以从上一个本身状态变化过来
 * 所以最后要求的答案即：dp[2].back()
 */

#include "Header.h"

using namespace std;

class Solution {
public:
  int minimumOperations(string leaves) {
    vector<vector<int>> dp(3, vector<int>(leaves.size(), 0));

    for (int i = 0; i < leaves.size(); i++) {
      if (i < 1)
        dp[0][i] = (leaves[i] != 'r');
      else
        dp[0][i] = dp[0][i - 1] + (leaves[i] != 'r');

      if (i < 1)
        dp[1][i] = dp[0][i];
      else
        dp[1][i] = min(dp[0][i - 1] + (leaves[i] != 'y'),
                       dp[1][i - 1] + (leaves[i] != 'y'));

      if (i < 2)
        dp[2][i] = dp[1][i];
      else
        dp[2][i] = min(dp[1][i - 1] + (leaves[i] != 'r'),
                       dp[2][i - 1] + (leaves[i] != 'r'));
    }

    return dp[2].back();
  }
};

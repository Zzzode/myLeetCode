/*
 * @lc app=leetcode.cn id=1505 lang=cpp
 *
 * [1505] 最多 K 次交换相邻数位后得到的最小整数
 *
 * https://leetcode-cn.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/description/
 *
 * algorithms
 * Hard (34.87%)
 * Likes:    41
 * Dislikes: 0
 * Total Accepted:    2.5K
 * Total Submissions: 7.3K
 * Testcase Example:  '"4321"\n4'
 *
 * 给你一个字符串 num 和一个整数 k 。其中，num
 * 表示一个很大的整数，字符串中的每个字符依次对应整数上的各个 数位 。
 *
 * 你可以交换这个整数相邻数位的数字 最多`k`次。
 *
 * 请你返回你能得到的最小整数，并以字符串形式返回。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：num = "4321", k = 4
 * 输出："1342"
 * 解释：4321 通过 4 次交换相邻数位得到最小整数的步骤如上图所示。
 *
 *
 * 示例 2：
 *
 *
 * 输入：num = "100", k = 1
 * 输出："010"
 * 解释：输出可以包含前导 0 ，但输入保证不会有前导 0 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：num = "36789", k = 1000
 * 输出："36789"
 * 解释：不需要做任何交换。
 *
 *
 * 示例 4：
 *
 *
 * 输入：num = "22", k = 22
 * 输出："22"
 *
 *
 * 示例 5：
 *
 *
 * 输入：num = "9438957234785635408", k = 23
 * 输出："0345989723478563548"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= num.length <= 30000
 * num 只包含 数字 且不含有 前导 0 。
 * 1 <= k <= 10^9
 *
 *
 */
#include "Header.h"
// @lc code=start
class BIT {
 private:
  vector<int> tree;
  int n;

 public:
  explicit BIT(int _n) : n(_n), tree(_n + 1) {}

  static int lowbit(int x) {
    return x & (-x);
  }

  void update(int x) {
    while (x <= n) {
      ++tree[x];
      x += lowbit(x);
    }
  }

  [[nodiscard]] int query(int x) const {
    int ans = 0;
    while (x) {
      ans += tree[x];
      x -= lowbit(x);
    }
    return ans;
  }

  [[nodiscard]] int query(int x, int y) const {
    return query(y) - query(x - 1);
  }
};

class Solution {
 public:
  string minInteger(string num, int k) {
    int n = num.length();
    vector<queue<int>> pos(10);
    for (int i = 0; i < n; ++i) { pos[num[i] - '0'].push(i + 1); }

    string ans;
    BIT bit(n);
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < 10; ++j) {
        if (pos[j].empty()) continue;

        int behind = bit.query(pos[j].front() + 1, n);
        int dist = pos[j].front() + behind - i;
        if (dist <= k) {
          bit.update(pos[j].front());
          pos[j].pop();
          ans += (j + '0');
          k -= dist;
          break;
        }
      }
    }
    return ans;
  }
};
// 0345989723478563548
// 0345989723478563548
// @lc code=end

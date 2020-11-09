/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 *
 * https://leetcode-cn.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (37.72%)
 * Likes:    224
 * Dislikes: 0
 * Total Accepted:    33.8K
 * Total Submissions: 88.5K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * 给出一个无重叠的 ，按照区间起始端点排序的区间列表。
 *
 * 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
 *
 *
 *
 * 示例 1：
 *
 * 输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
 * 输出：[[1,5],[6,9]]
 *
 *
 * 示例 2：
 *
 * 输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * 输出：[[1,2],[3,10],[12,16]]
 * 解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
 *
 *
 *
 *
 * 注意：输入类型已在 2019 年 4 月 15
 * 日更改。请重置为默认代码定义以获取新的方法签名。
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& ne) {
    int n = in.size();

    if (n == 0) return {ne};
    if (ne[0] > in[n - 1][1]) {
      in.push_back({ne[0], ne[1]});
      return in;
    }
    if (ne[1] < in[0][0]) {
      in.insert(in.begin(), {ne[0], ne[1]});
      return in;
    }

    int i = 0;
    vector<vector<int>> ans;
    while (i < n && ne[0] > in[i][1]) ans.emplace_back(in[i++]);

    int n0 = min(ne[0], in[i][0]);
    int n1 = n0 - 1;
    while (i < n) {
      if (ne[1] < in[i][0] || ne[1] <= in[i][1]) {
        n1 = ne[1] >= in[i][0] ? in[i++][1] : ne[1];
        break;
      }
      i++;
    }
    ans.push_back({n0, n1 < n0 ? ne[1] : n1});
    while (i < n) ans.emplace_back(in[i++]);

    return ans;
  }
};
// @lc code=end

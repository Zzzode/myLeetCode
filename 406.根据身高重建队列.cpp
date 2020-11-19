/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 *
 * https://leetcode-cn.com/problems/queue-reconstruction-by-height/description/
 *
 * algorithms
 * Medium (67.29%)
 * Likes:    658
 * Dislikes: 0
 * Total Accepted:    65.5K
 * Total Submissions: 92.2K
 * Testcase Example:  '[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]'
 *
 * 假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h,
 * k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。
 * 编写一个算法来重建这个队列。
 *
 * 注意：
 * 总人数少于1100人。
 *
 * 示例
 *
 *
 * 输入:
 * [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 *
 * 输出:
 * [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(),
         [](const vector<int>& u, const vector<int>& v) {
           return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
         });
    vector<vector<int>> ans;
    for (const vector<int>& person : people) {
      ans.insert(ans.begin() + person[1], person);
    }
    return ans;
  }
};
// @lc code=end

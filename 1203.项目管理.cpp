/*
 * @lc app=leetcode.cn id=1203 lang=cpp
 *
 * [1203] 项目管理
 *
 * https://leetcode-cn.com/problems/sort-items-by-groups-respecting-dependencies/description/
 *
 * algorithms
 * Hard (39.74%)
 * Likes:    141
 * Dislikes: 0
 * Total Accepted:    8.9K
 * Total Submissions: 13.8K
 * Testcase Example:
 * '8\n2\n[-1,-1,1,0,0,1,0,-1]\n[[],[6],[5],[6],[3,6],[],[],[]]'
 *
 * 公司共有 n 个项目和  m 个小组，每个项目要不无人接手，要不就由 m
 * 个小组之一负责。
 *
 * group[i] 表示第 i 个项目所属的小组，如果这个项目目前无人接手，那么 group[i]
 * 就等于
 * -1。（项目和小组都是从零开始编号的）小组可能存在没有接手任何项目的情况。
 *
 * 请你帮忙按要求安排这些项目的进度，并返回排序后的项目列表：
 *
 *
 * 同一小组的项目，排序后在列表中彼此相邻。
 * 项目之间存在一定的依赖关系，我们用一个列表
 * beforeItems 来表示，其中 beforeItems[i] 表示在进行第 i 个项目前（位于第 i
 * 个项目左侧）应该完成的所有项目。
 *
 *
 * 如果存在多个解决方案，只需要返回其中任意一个即可。如果没有合适的解决方案，就请返回一个
 * 空列表 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems =
 * [[],[6],[5],[6],[3,6],[],[],[]]
 * 输出：[6,3,4,1,5,2,0,7]
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems =
 * [[],[6],[5],[6],[3],[],[4],[]]
 * 输出：[]
 * 解释：与示例 1 大致相同，但是在排序后的列表中，4 必须放在 6 的前面。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * group.length == beforeItems.length == n
 * -1
 * 0
 * 0
 * i != beforeItems[i][j]
 * beforeItems[i] 不含重复元素
 *
 *
 */
#include "Header.h"
// @lc code=start
class Solution {
public:
  vector<int> sortItems(int n,
                        int m,
                        vector<int>& group,
                        vector<vector<int>>& beforeItems) {
    ;
  }
};
// @lc code=end

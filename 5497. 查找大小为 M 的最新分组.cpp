#include <algorithm>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
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
  int findLatestStep(vector<int>& arr, int m) {
    int n = arr.size();
    if (n == m) {
      return n;
    }

    // span的每一个元素存放一个111序列;
    map<int, int> span = {{1, n}};

    for (int i = n - 1; i >= 0; --i) {
      //找到当前变换位置所属的区间;
      auto it     = prev(span.upper_bound(arr[i]));
      auto [l, r] = *it;
      if (arr[i] - l == m || r - arr[i] == m) {
        return i;
      }

      //该位置变为0，当前区间分开成2个子区间;
      span.erase(it);
      if (l <= arr[i] - 1) {
        span.emplace(l, arr[i] - 1);
      }
      if (arr[i] + 1 <= r) {
        span.emplace(arr[i] + 1, r);
      }
    }
    return -1;
  }
};
// @lc code=end
/*
将题目转换成 [1,1,1] --> [0,0,0]
求最开始出现的 长度为m的一组1

map<int,int> span 存放 子序列
span的每一个元素{left, right} 存放一个连续1序列,对应区间 [left, right]

每次填充一个0，会将span中的某一个区间分成2个区间，
当出现某一个子区间的长度为m时，流程结束
*/

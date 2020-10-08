/*
 * 有一个整数数组nums，和一个查询数组requests，其中requests[i]=[starti,endi]
 * 第i个查询求nums[starti] + nums[starti + 1] + ... + nums[endi] 的结果 ，starti
 * 和 endi 数组索引都是 从 0 开始 的。你可以任意排列 nums
 * 中的数字，请你返回所有查询结果之和的最大值。由于答案可能会很大，请你将它对
 * 109 + 7 取余 后返回。
 */

#include "Header.h"

#define MOD 1000000007
using LL = long long;

class Solution {
public:
  int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
    int size = nums.size();

    vector<int> freq(size + 1);
    for (auto v : requests) {
      freq[v[0]]++;
      freq[v[1] + 1]--;
    }

    for (int i = 1; i <= size; i++)
      freq[i] += freq[i - 1];

    sort(freq.begin(), freq.begin() + size);
    sort(nums.begin(), nums.end());

    LL ans = 0;
    for (int i = size - 1; i >= 0; i--)
      ans = (ans + (LL)nums[i] * freq[i]) % MOD;

    return ans;
  }
};
// 596658136

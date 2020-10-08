#include "Header.h"
/*
 * 给你一个正整数数组 arr ，请你计算所有可能的奇数长度子数组的和。
 * 子数组 定义为原数组中的一个连续子序列。
 * 请你返回 arr 中 所有奇数长度子数组的和 。
 */
class Solution {
public:
  int sumOddLengthSubarrays(vector<int>& arr) {
    int ans = 0;
    int size = arr.size();
    for (int len = 1; len <= size; len += 2) {
      for (int i = 0; i < size - len + 1; i++) {
        for (int j = i; j < i + len; j++) {
          // cout << arr[j] << " ";
          ans += arr[j];
        }
        // cout << endl;
      }
    }
    return ans;
  }
};

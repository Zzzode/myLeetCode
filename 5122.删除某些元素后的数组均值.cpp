#include "Header.h"

class Solution {
 public:
  double trimMean(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int sum = 0, len = arr.size() * 0.05;
    for (int i = len; i < arr.size() - len; i++) { sum += arr[i]; }
    double ans = (double)sum / (double)(arr.size() - 2 * len);
    return ans;
  }
};

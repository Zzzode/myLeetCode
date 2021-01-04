#include "Header.h"

class Solution {
public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    int n = boxTypes.size();
    for (int i = 0; i < n; i++) swap(boxTypes[i][0], boxTypes[i][1]);
    sort(boxTypes.begin(), boxTypes.end(), greater<>());

    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (boxTypes[i][1] <= truckSize) {
        ans += boxTypes[i][0] * boxTypes[i][1];
        truckSize -= boxTypes[i][1];
      } else {
        ans += truckSize * boxTypes[i][0];
        break;
      }
    }

    return ans;
  }
};

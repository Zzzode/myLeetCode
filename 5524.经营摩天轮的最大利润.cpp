#include "Header.h"

class Solution {
public:
  int minOperationsMaxProfit(vector<int>& customers,
                             int boardingCost,
                             int runningCost) {
    if (4 * boardingCost <= runningCost)
      return -1;

    int ans = 0;
    int max = INT_MIN;
    int ints = 0;

    vector<int> help;

    for (int i = 0; i < customers.size(); i++) {
      if (customers[i] > 4) {
        if (i == customers.size() - 1)
          customers.push_back(customers[i] - 4);
        else
          customers[i + 1] += customers[i] - 4;
        customers[i] = 4;
      }
      ints += customers[i] * boardingCost - runningCost;
      // cout << "当前人数 " << customers[i] << " " << ints << endl;
      help.emplace_back(ints);
    }

    for (int i = 0; i < help.size(); i++) {
      if (help[i] > max) {
        ans = i + 1;
        max = help[i];
      }
    }

    return ans;
  }
};

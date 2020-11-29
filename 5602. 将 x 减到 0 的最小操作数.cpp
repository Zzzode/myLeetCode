#include "Header.h"

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int ans = -1;
        int n = nums.size();

        unordered_map<int, int> ma;
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
            ma[nums[i]] = i;
        }

        x = nums[n - 1] - x;

        for (int i = 0; i < n; i++) {
            int a = i > 0 ? nums[i - 1] : 0;
            if (ma.count(a + x)) {
                int res = i + n - ma[a + x] - 1;
                ans = ans == -1 ? res : min(ans, res);
            }
        }

        return ans;
    }
};

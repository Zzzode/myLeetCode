#include "Header.h"

using pii = pair<int, int>;
class Solution {
  public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, set<int>> ma;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            // v.emplace_back(nums[i], i);
            ma[nums[i]].emplace(i);
        }
        // sort(v.begin(), v.end());

        return ans;
    }
};

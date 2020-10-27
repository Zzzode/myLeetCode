#include "Header.h"

class Solution {
 public:
  char slowestKey(vector<int>& releaseTimes, string keysPressed) {
    unordered_map<int, vector<char>> h;
    int maxT = releaseTimes[0];
    h[releaseTimes[0]].emplace_back(keysPressed[0]);
    for (int i = 1; i < releaseTimes.size(); i++) {
      h[releaseTimes[i] - releaseTimes[i - 1]].emplace_back(keysPressed[i]);
      maxT = max(maxT, releaseTimes[i] - releaseTimes[i - 1]);
    }

    return *max_element(h[maxT].begin(), h[maxT].end());
  }
};

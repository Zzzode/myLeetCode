#include "Header.h"

#define MOD 1000000007

using ull = unsigned long long;
template <typename T> using umset = unordered_multiset<T>;
template <typename T> using uset = unordered_set<T>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2>;
template <typename T> using v2 = vector<vector<T>>;
template <typename T> using v1 = vector<T>;

class Solution {
 public:
  int countVowelStrings(int n) {
    v1<int> num(5, 1);

    while (--n)
      for (int i = 1; i < 5; i++) num[i] += num[i - 1];

    return num[0] + num[1] + num[2] + num[3] + num[4];
  }
};

int main() {
  Solution solution;
  int ans = 0;
  v1<int> arr{37, 69, 3, 74, 46};
  v2<int> pieces{{37, 69, 3, 74, 46}};
  int n = 0, bricks = 0, ladders = 0;
  //  ans = solution.furthestBuilding(arr, bricks, ladders);
  ans = solution.countVowelStrings(33);
  cout << ans << endl;

  return 0;
}
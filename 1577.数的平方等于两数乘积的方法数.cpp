#include "Header.h"

using ULL = unsigned long long;

class Solution {
public:
  int numTriplets(vector<int>& nums1, vector<int>& nums2) {
    ULL ans = 0;
    int size1 = nums1.size(), size2 = nums2.size();

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    unordered_map<ULL, int> pow21;
    unordered_map<ULL, int> pow22;

    for (int i = 0; i < size1; i++)
      pow21[(ULL)nums1[i] * (ULL)nums1[i]] += 1;

    for (int i = 0; i < size2; i++)
      pow22[(ULL)nums2[i] * (ULL)nums2[i]] += 1;

    // for (auto a : pow21)
    //   cout << a.first << "," << a.second << " ";
    // cout << endl;

    for (int i = 0; i < size1 - 1; i++) {
      for (int j = i + 1; j < size1; j++)
        ans += ((ULL)nums1[i] * (ULL)nums1[j] *
                pow22[(ULL)nums1[i] * (ULL)nums1[j]]) > 0 ?
                   pow22[(ULL)nums1[i] * (ULL)nums1[j]] :
                   0;
    }
    for (int i = 0; i < size2 - 1; i++) {
      for (int j = i + 1; j < size2; j++)
        ans += ((ULL)nums2[i] * (ULL)nums2[j] *
                pow21[(ULL)nums2[i] * (ULL)nums2[j]]) > 0 ?
                   pow21[(ULL)nums2[i] * (ULL)nums2[j]] :
                   0;
    }

    return ans;
  }
};

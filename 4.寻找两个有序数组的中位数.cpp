/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */
#include "Header.h"
// @lc code=start
class Solution {
  public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        bool is_odd;

        if (nums1.empty() && ~nums2.empty()) {
            if (nums2.size() % 2 != 0) return nums2[nums2.size() / 2];
            else
                return (nums2[nums2.size() / 2] + nums2[nums2.size() / 2 - 1]) /
                       2.0;
        } else if (nums2.empty() && ~nums1.empty()) {
            if (nums1.size() % 2 != 0) return nums1[nums1.size() / 2];
            else
                return (nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) /
                       2.0;
        } else {
            // 当数组都为非空的时候
            if ((nums1.size() + nums2.size()) % 2 != 0) {
                k = (nums1.size() + nums2.size()) / 2 + 1;
                is_odd = true;
            } else {
                k = (nums1.size() + nums2.size()) / 2;
                is_odd = false;
            }

            while (k != 1) {
                // 整理两个数组，直到k = 1，也就是需要读两个数组中最小的1个数据
                // 当然m+n为偶数时，需要判断，读取2个数组中最小的2个数之和，并除以2
                int i = (k - 1) / 2 - 1;

                if (i == -1) {
                    nums1[0] <= nums2[0] ? nums1.erase(nums1.begin()) :
                                           nums2.erase(nums2.begin());
                    k -= 1;
                } else if (nums1.size() <= i + 1) {
                    if (nums1.back() <= nums2[i]) {
                        k -= nums1.size();
                        nums1.clear();
                        break;
                    } else {
                        nums2.erase(nums2.begin(), nums2.begin() + i + 1);
                        k = k - i - 1;
                    }
                } else if (nums2.size() <= i + 1) {
                    if (nums2.back() <= nums1[i]) {
                        k -= nums2.size();
                        nums2.clear();
                        break;
                    } else {
                        nums1.erase(nums1.begin(), nums1.begin() + i + 1);
                        k = k - i - 1;
                    }
                } else {
                    if (nums1[i] <= nums2[i]) {
                        nums1.erase(nums1.begin(), nums1.begin() + i + 1);
                    } else {
                        nums2.erase(nums2.begin(), nums2.begin() + i + 1);
                    }
                    k = k - i - 1;
                }
            }

            if (nums1.empty()) {
                if (is_odd) return nums2[k - 1];
                else
                    return (nums2[k - 1] + nums2[k]) / 2.0;
            } else if (nums2.empty()) {
                if (is_odd) return nums1[k - 1];
                else
                    return (nums1[k - 1] + nums1[k]) / 2.0;
            } else {
                if (is_odd) return nums1[0] < nums2[0] ? nums1[0] : nums2[0];
                else {
                    if (nums1.size() > nums2.size()) {
                        if (nums2.size() > 1) {
                            if (nums2[1] < nums1[0])
                                return (nums2[0] + nums2[1]) / 2.0;
                            else if (nums1[1] < nums2[0])
                                return (nums1[0] + nums1[1]) / 2.0;
                            else
                                return (nums1[0] + nums2[0]) / 2.0;
                        } else {
                            if (nums1[1] < nums2[0])
                                return (nums1[0] + nums1[1]) / 2.0;
                            else
                                return (nums1[0] + nums2[0]) / 2.0;
                        }
                    } else if (nums1.size() < nums2.size()) {
                        if (nums1.size() > 1) {
                            if (nums1[1] < nums2[0])
                                return (nums1[0] + nums1[1]) / 2.0;
                            else if (nums2[1] < nums1[0])
                                return (nums2[0] + nums2[1]) / 2.0;
                            else
                                return (nums1[0] + nums2[0]) / 2.0;
                        } else {
                            if (nums2[1] < nums1[0])
                                return (nums2[0] + nums2[1]) / 2.0;
                            else
                                return (nums1[0] + nums2[0]) / 2.0;
                        }
                    } else {
                        if (nums1.size() > 1) {
                            if (nums1[1] <= nums2[0])
                                return (nums1[0] + nums1[1]) / 2.0;
                            else if (nums2[1] <= nums1[0])
                                return (nums2[0] + nums2[1]) / 2.0;
                            else
                                return (nums1[0] + nums2[0]) / 2.0;
                        } else
                            return (nums1[0] + nums2[0]) / 2.0;
                    }
                }
            }
        }
    }

  private:
    int k = 0;
};
// @lc code=end

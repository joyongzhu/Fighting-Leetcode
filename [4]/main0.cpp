/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 * 
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 */
#include <vector>
#include <iostream>
#include <algorithm>

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int nums1_size = nums1.size();
        int nums2_size = nums2.size();
        int num = nums1_size + nums2_size;
        double medium_num = 0;
        int nums1_index = 0;
        int nums2_index = 0;

        std::vector<int> sortedNum;
        while (true) {
            if (nums1_index < nums1_size && nums2_index < nums2_size) {
                if (nums1[nums1_index] <= nums2[nums2_index]) {
                    sortedNum.push_back(nums1[nums1_index]);
                    nums1_index++;
                }
                else {
                    sortedNum.push_back(nums2[nums2_index]);
                    nums2_index++;
                }
            }
            else if (nums1_index < nums1_size) {
                sortedNum.push_back(nums1[nums1_index]);
                nums1_index++;
            }
            else if (nums2_index < nums2_size) {
                sortedNum.push_back(nums2[nums2_index]);
                nums2_index++;
            }
            else {
                break;
            }
        }

        if (num % 2 == 0) {
            medium_num = (sortedNum[num/2 - 1] + sortedNum[num/2])/2.0;
        }
        else {
            medium_num = sortedNum[num/2]; 
        }
        return medium_num;
    }
};
// @lc code=end


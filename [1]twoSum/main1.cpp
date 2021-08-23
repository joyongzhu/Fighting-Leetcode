/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 * https://leetcode-cn.com/problems/two-sum/description/
 */
#include <vector>

// @lc code=start
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> result;

        int nums_size = nums.size();
        for (int i = 0; i < nums_size; i++) {
            for (int j  = i + 1; j < nums_size; j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);

                    return result;
                } 
            }
        }

        return result;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> result;
        std::map<int, int> tmp;
        for (size_t i = 0; i < nums.size(); i++) {
            if (tmp.find(target-nums[i]) != tmp.end() && tmp[target-nums[i]] != i) {
                result.push_back(tmp[target - nums[i]]);
                result.push_back(i);

                return result;
            }
            // 之所以 要放在 for 后， 是因为如果放在前面，
            // 相同的值会更新 index， 导致无法知道上一个 index是多少
            tmp[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end


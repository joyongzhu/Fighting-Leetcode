// 一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
// 链接：https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof

// Examples:    input: [0,1,2,3,4,5,6,7,9]     output: 8
// author:      ZhuYong
// date:        2020/9/27

#include <vector>
#include <iostream>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size();

        while (left < right) {
            int median = ( left + right)/2;

            if (median == nums[median]) {
                left = median + 1;
            } else {
                right = median;
            }
        }
        return right;
    }
};

int main()
{
    int array1[2] = {0, 1};

    std::vector<int> nums;
    nums.insert(nums.begin(), &array1[0], &array1[2]);

    std::cout << "output:" << Solution().missingNumber(nums) << std::endl;

    return 0;
}
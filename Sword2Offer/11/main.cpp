// 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。
// 链接：https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof

// Examples:    input: [3,4,5,1,2]     output: 1
// author:      ZhuYong
// date:        2020/9/27

#include <vector>
#include <iostream>

class Solution {
public:
    int minArray(std::vector<int>& numbers) {
        int left = 0, right = numbers.size() - 1;

        while (left < right) {
            int mid = (left + right)/2;
            if (numbers[mid] > numbers[right]) {
                left = mid + 1;
            } 
            else if (numbers[mid] < numbers[right]) {
                right = mid;
            }
            else {
                right -= 1;
            }
        }
        return numbers[left];
    }
};

int main()
{
    std::vector<int> list1 = {3, 1, 3};
    std::cout << "result:" << Solution().minArray(list1) << std::endl;

    return 0;
}
/*
 * @lc app=leetcode.cn id=1646 lang=cpp
 *
 * [1646] 获取生成数组中的最大值
 */

#include <string>
#include <vector>
#include <map>

// @lc code=start
class Solution {
public:
    int getMaximumGenerated(int n) {
        std::map<int, int> map_result;
        if (n == 0)
            return 0;

        if (n == 1)
            return 1;

        map_result[0] = 0;
        map_result[1] = 1;

        int max_num = 0;
        for (int i = 2; i <= n; i++) {
            if (i % 2) {
                map_result[i] = map_result[i/2] + map_result[i/2+1];
            }
            else {
                map_result[i] = map_result[i/2];
            }

            if (map_result[i] >= max_num)
                max_num = map_result[i];
        }
        return max_num;
    }
};
// @lc code=end

int main()
{
    Solution solu;
    solu.getMaximumGenerated(99);
    return 0;
}
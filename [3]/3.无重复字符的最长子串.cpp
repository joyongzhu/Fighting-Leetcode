/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 * 
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 */

#include <string>
#include <map>
#include <iostream>

// @lc code=start

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.size() == 0) return 0;
        if (s.size() == 1) return 1;

        int left = 0;
        int right = 0;
        size_t the_max_len = 0;
        size_t current_len = 0;
        size_t size = s.length();

        for (size_t i = 0; i < size; i++) {
            right++;

            // 如果在 left 和 right(不包括) 之间的字符串里找到了 right 所在字符
            size_t the_repeated_one = s.substr(left, right-left).find(s[right]);
            if (the_repeated_one != std::string::npos) {
                std::cout << left << " " << right << " " << the_max_len;
                the_max_len = right - left > the_max_len ? right - left : the_max_len;
                left = the_repeated_one + left + 1;
                std::cout << " " << left << " " << the_repeated_one << " " << the_max_len << std::endl;
                current_len = 0;
                //std::cout << s.substr(left, right-left) << std::endl;
            }
            // 如果没找到 right 所在字符
            else {
                current_len++;
            }
        }

        the_max_len = size - left > the_max_len ? size - left : the_max_len;

        return the_max_len;

    }
};
// @lc code=end


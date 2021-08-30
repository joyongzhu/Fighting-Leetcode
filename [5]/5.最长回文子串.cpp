/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <string>
#include <iostream>

// @lc code=start
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.size() == 1) return s;

        int index = 0;
        int result_offset = 0;

        // in the middle is one character
        for (int i = 0; i < s.size(); i++) {
            int offset = 0;
            while (i - offset > 0 && i + offset < s.size() - 1) {
                offset ++;
                if (s[i-offset] == s[i+offset]) {
                    if (offset > result_offset) {
                        index = i;
                        result_offset = offset;
                    }
                    continue;
                }
                else {
                    break;   
                }
            }
        }

        // in the middle is two characters
        int index_1 = 0;
        int result_offset_1 = 0;
        bool middle_is_two = false;
        for (int i = 0; i < s.size(); i++) {
            // 当是最后一位时
            if (i + 1 == s.size())
                break;

            if (s[i] != s[i+1] )
                continue;

            middle_is_two = true;

            int offset_1 = 0;
            while (i - offset_1 >= 0 && i + 1 + offset_1 < s.size()) {
                if (s[i-offset_1] == s[i+1+offset_1]) {
                    if (offset_1 >= result_offset_1) {
                        index_1 = i;
                        result_offset_1 = offset_1;
                    }
                }
                else {
                    break;
                }
                offset_1 ++;
            }
        }

        if (middle_is_two) {
            if (result_offset_1 >= result_offset) {
                return s.substr(index_1 - result_offset_1, result_offset_1 + 2 + result_offset_1);
            }
            else {
                return s.substr(index - result_offset, result_offset + 1 + result_offset);   
            }
            return s.substr(0, 1);
        }
        else {
            if (index != 0) {
                return s.substr(index - result_offset, result_offset + 1 + result_offset);   
            }  
            return s.substr(0, 1);
        }
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
#include <string>
#include <iostream>

// @lc code=start
class Solution {
public:
    int romanToInt(std::string s) {
        int result = 0;
        while (s.length() != 0) {
            result += convert(s);
        }
        return result;
    }

    int convert(std::string &s) {
        if (s.compare(0, 1, "M") == 0) {
            s = s.substr(1);
            return 1000;
        }
        if (s.compare(0, 2, "CM") == 0) {
            s = s.substr(2);
            return 900;
        }
        if (s.compare(0, 1, "D") == 0) {
            s = s.substr(1);
            return 500;
        }
        if (s.compare(0, 2, "CD") == 0) {
            s = s.substr(2);
            return 400;
        }
        if (s.compare(0, 1, "C") == 0) {
            s = s.substr(1);
            return 100;
        }
        if (s.compare(0, 2, "XC") == 0) {
            s = s.substr(2);
            return 90;
        }
        if (s.compare(0, 1, "L") == 0) {
            s = s.substr(1);
            return 50;
        }
        if (s.compare(0, 2, "XL") == 0) {
            s = s.substr(2);
            return 40;
        }
        if (s.compare(0, 1, "X") == 0) {
            s = s.substr(1);
            return 10;
        }
        if (s.compare(0, 2, "IX") == 0) {
            s = s.substr(2);
            return 9;
        }
        if (s.compare(0, 1, "V") == 0) {
            s = s.substr(1);
            return 5;
        }
        if (s.compare(0, 2, "IV") == 0) {
            s = s.substr(2);
            return 4;
        }
        if (s.compare(0, 1, "I") == 0) {
            if (s.length() == 1) {
                s = "";
                return 1;
            }
            s = s.substr(1);
            return 1;
        }

        return 0;
    }
};
// @lc code=end

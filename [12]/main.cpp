/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
#include <string>
#include <iostream>

class Solution {
public:
    std::string intToRoman(int num) {
        std::string result = "";
        while (num != 0) {
            result += classify(num);
        }
        return result;
    }

    std::string classify(int &num) {
        if (num >= 1 && num < 4) {
            num -= 1;
            return "I";
        }
        else if (num >= 4 && num < 5) {
            num -= 4;
            return "IV";
        }
        else if (num >= 5 && num < 9) {
            num -= 5;
            return "V";
        }
        else if (num >= 9 && num < 10) {
            num -= 9;
            return "IX";
        }
        else if (num >= 10 && num < 40) {
            num -= 10;
            return "X";
        }
        else if (num >= 40 && num < 50) {
            num -= 40;
            return "XL";
        }
        else if (num >= 50 && num < 90) {
            num -= 50;
            return "L";
        }
        else if (num >= 90 && num < 100) {
            num -= 90;
            return "XC";
        }
        else if (num >= 100 && num < 400) {
            num -= 100;
            return "C";
        }
        else if (num >= 400 && num < 500) {
            num -= 400;
            return "CD";
        }
        else if (num >= 500 && num < 900) {
            num -= 500;
            return "D";
        }
        else if (num >= 900 && num < 1000) {
            num -= 900;
            return "CM";
        }
        else { //num >= 1000 && num < 9000
            num -= 1000;
            return "M";
        }

    }
};
// @lc code=end

int main() {
    Solution result;
    std::cout << result.intToRoman(9) << std::endl;

    return 0;
}



/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */
#include <string>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        string res;

        while(num / 1000)
        {
            res.append("M");
            num -= 1000;
        }

        if(num/100 == 4)
        {
            res.append("CD");
            num -= 400;
        }
        else if(num/100 == 9)
        {
            res.append("CM");
            num -= 900;
        }
        else
        {
            if(num/100 >= 5)
            {
                res.append("D");
                num -= 500;
            }
            while(num/100)
            {
                res.append("C");
                num -= 100;
            }
        }

        if(num/10 == 4)
        {
            res.append("XL");
            num -= 40;
        }
        else if(num/10 == 9)
        {
            res.append("XC");
            num -= 90;
        }
        else
        {
            if(num/10 >= 5)
            {
                res.append("L");
                num -= 50;
            }
            while(num/10)
            {
                res.append("X");
                num -= 10;
            }
        }

        if(num == 4)
        {
            res.append("IV");
            num -= 4;
        }
        else if(num == 9)
        {
            res.append("IX");
            num -= 9;
        }
        else
        {
            if(num >= 5)
            {
                res.append("V");
                num -= 5;
            }
            while(num)
            {
                res.append("I");
                num -= 1;
            }
        }

        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.intToRoman(1994);
    return 0;
}
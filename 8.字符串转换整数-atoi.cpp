/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include <string>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int res = 0;
        int sign = 1;
        int i = 0;
        for(; i < s.size(); i++)
        {
            if(s[i] != ' ')
            {
                break;
            }
        }
        if(i >= s.size()) return 0;
        if(s[i] == '-') 
        {
            sign = -1;
            i++;
            if(i >= s.size()) return 0;
        }
        else if (s[i] == '+')
        {
            sign = 1;
            i++;
            if(i >= s.size()) return 0;
        }
        
        if(s[i] >= '0' && s[i] <= '9')
        {
            res = (s[i] - '0') * sign;
        }
        else
        {
            return 0;
        }
        i++;
        if(i >= s.size()) return res;

        for(; i <s.size(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                int num = s[i] - '0';
                if(sign == 1)
                {
                    if(INT32_MAX / 10 < res) return INT32_MAX;
                    res *= 10;
                    if(INT32_MAX - num < res) return INT32_MAX;
                    res += num;
                }
                else
                {
                    if(INT32_MIN / 10 > res) return INT32_MIN;
                    res *= 10;
                    if(INT32_MIN + num > res) return INT32_MIN;
                    res -= num;
                }
            }
            else
            {
                return res;
            }
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.myAtoi("-2147483649");
    return 0;
}
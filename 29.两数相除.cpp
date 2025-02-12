/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */
#include <cmath>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign1 = signbit(dividend);
        bool sign2 = signbit(divisor);
        int sign = sign1^sign2 ? 1 : -1;
        int res = 0;
        while(signbit(dividend) == sign1)
        {
            dividend += sign * divisor;
            res--;
        }
        if(dividend != 0)res++;
        if(sign == -1 && res == INT32_MIN)
        {
            return INT32_MAX;
        }
        return sign * res;
    }
};
// @lc code=end


int main()
{
    Solution s;
    cout << s.divide(-7, 3);
    return 0;
}
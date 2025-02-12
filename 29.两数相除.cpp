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
        if(dividend == INT32_MIN && divisor == 1) return INT32_MIN;
        if(dividend == INT32_MIN && divisor == -1) return INT32_MAX;
        if(dividend == INT32_MIN && divisor == INT32_MIN) return 1;
        if(dividend == INT32_MIN && divisor == INT32_MAX) return -1;
        if(divisor == 1) return dividend;
        if(divisor == -1) return -dividend;

        bool sign1 = signbit(dividend);
        bool sign2 = signbit(divisor);
        int sign = sign1^sign2 ? -1 : 1;
        if(!sign1) dividend = -dividend;
        if(!sign2) divisor = -divisor;

        if(divisor < dividend) return 0;

        int res_l = 1;
        int res_h = -(dividend >> 1) + 1;
        int res;

        auto quickAdd = [](int y, int z, int x) {
            // x 和 y 是负数，z 是正数
            // 需要判断 z * y >= x 是否成立
            int result = 0, add = y;
            while (z) {
                if (z & 1) {
                    // 需要保证 result + add >= x
                    if (result < x - add) {
                        return false;
                    }
                    result += add;
                }
                if (z != 1) {
                    // 需要保证 add + add >= x
                    if (add < x - add) {
                        return false;
                    }
                    add += add;
                }
                // 不能使用除法
                z >>= 1;
            }
            return true;
        };

        while(res_l < res_h)
        {
            res = res_l + ((res_h - res_l) >> 1);

            if(quickAdd(divisor, res, dividend))
            {
                if(res_l == res) return sign * res;
                res_l = res;
            }
            else
            {
                if(res_h == res) return sign * res;
                res_h = res;
            }
        }
        return sign * res;
    }
};
// @lc code=end


int main()
{
    Solution s;
    cout << s.divide(14, 7);
    return 0;
}
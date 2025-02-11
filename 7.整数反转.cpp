/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include <cmath>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int reverse(int x) {
        if(x < 10 && x > -10)
        {
            return x;
        }
        int res = 0;
        while(x)
        {
            int temp = x % 10;
            if(res > 0 && INT32_MAX / 10 < res) return 0;
            if(res < 0 && INT32_MIN / 10 > res) return 0;
            res *= 10;
            if(res > 0 && INT32_MAX - res < temp) return 0;
            if(res < 0 && INT32_MIN - res > temp) return 0;
            res += temp;
            x /= 10;
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.reverse(-2147483648);
    return 0;
}
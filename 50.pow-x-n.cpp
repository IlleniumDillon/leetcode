/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */
#include <cmath>
using namespace std;
// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return 0;
        if(n == 0) return 1;
        long long n_ = n;
        if(n_ < 0) 
        {
            x = 1/x;
            n_ = -n_;
        }
        double res = 1;
        double sq = x;
        while(n_ > 0)
        {
            if(n_%2 == 1)
            {
                res = res * sq;
                n_--;
            }

            sq = sq * sq;
            n_ /= 2;
        }
        return res;
    }
};
// @lc code=end


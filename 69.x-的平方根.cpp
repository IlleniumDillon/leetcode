/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x == 1) return 1;
        int l = 0, h = x;
        int m, ans;
        while(l<=h)
        {
            m = (l + h) / 2;
            if(x / m < m)
            {
                h = m - 1;
            }
            else if(x / m > m)
            {
                l = m + 1;
                ans = m;
            }
            else
            {
                return m;
            }
        }
        return ans;
    }
};
// @lc code=end


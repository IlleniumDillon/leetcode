/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

#include <cmath>

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x < 0) return false;
        if(x / 10 == 0) return true;
        
        int len = (int)log10(x) + 1;
        int checkNum = len / 2;
        int up = pow(10, len-1);
        int down = 1;

        for(int i = 0; i < checkNum; i++)
        {
            int u = (x / up) % 10;
            int d = (x % (down * 10)) / down;
            if(u != d) return false;
            up /= 10;
            down *= 10;
        }

        return true;
    }
};
// @lc code=end


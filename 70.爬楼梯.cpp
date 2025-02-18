/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
#include <map>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int p0 = 1, p1 = 2, p3;
        for(int i = 2; i < n; i++)
        {
            p3 = p0 + p1;
            p0 = p1;
            p1 = p3;
        }
        return p3;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

#include <map>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    int romanToInt(string s) 
    {
        map<char, int> values = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        if(s.length() == 1) return values[s[0]];

        int res = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(i + 1 >= s.length()) 
            {
                res += values[s[i]];
                break;
            }
            int cur = values[s[i]];
            int next = values[s[i + 1]];
            if(cur >= next)
            {
                res += cur;
            }
            else
            {
                res += (next - cur);
                i++;
            }
        }

        return res;
    }
};
// @lc code=end


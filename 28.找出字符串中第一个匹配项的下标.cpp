/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */
#include <string>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int p1 = 0, p2 = p1 + needle.size();
        for(;p1 <= (int)haystack.size() - (int)needle.size(); p1++)
        {
            string s = haystack.substr(p1, needle.size());
            if(s == needle)
            {
                return p1;
            }
        }
        return -1;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.strStr("a","aa") << endl;
    return 0;
}
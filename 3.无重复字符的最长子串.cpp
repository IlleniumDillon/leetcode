/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++)
        {
            unordered_set<char> cset;
            for(int j = i; j < s.size(); j++)
            {
                if(cset.count(s[j]) == 0)
                {
                    cset.insert(s[j]);
                }
                else
                {
                    break;
                }
            }
            res = res < cset.size() ? cset.size() : res;
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("pwwkew");
    return 0;
}
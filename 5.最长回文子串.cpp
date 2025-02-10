/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <string>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        if(s.size() == 1) return s;
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = s.size() - 1; j > i; j--)
            {
                if(s[i] == s[j])
                {
                    string t = s.substr(i, j - i + 1);
                    string r = t;
                    reverse(r.begin(), r.end());
                    if(t == r)
                    {
                        res = res.length() < t.length() ? t : res;
                        break;
                    }
                }
            }
        }
        if(res == "") res = s[0];
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    string o = s.longestPalindrome("aacabdkacaa");
    cout << o;
}
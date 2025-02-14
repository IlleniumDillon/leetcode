/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */
#include <string>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int i = s.size() - 1;
        while(i >= 0)
        {
            if(s[i]!=' ') break;
            i--;
        }
        while(i>=0)
        {
            if(s[i] == ' ') break;
            res++;
            i--;
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.lengthOfLastWord("luffy is still joyboy") << endl;
    return 0;
}
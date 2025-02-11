/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> subfun(string prefix, string s)
    {
        vector<string> res;
        if(s == "") 
        {
            res.push_back(prefix);
            return res;
        }
        for(auto & c : dict[s[0]])
        {
            auto temp = subfun(prefix + string(1, c), s.substr(1));
            res.insert(res.end(), temp.begin(), temp.end());
        }
        return res;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        for(auto & c : dict[digits[0]])
        {
            auto temp = subfun(string(1, c), digits.substr(1));
            res.insert(res.end(), temp.begin(), temp.end());
        }
        return res;
    }
    map<char, string> dict = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
};
// @lc code=end

int main()
{
    Solution s;
    auto res = s.letterCombinations("234");
    for(auto i : res)
    {
        cout << i << " ";
    }
    return 0;
}
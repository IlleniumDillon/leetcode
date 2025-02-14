/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 0;
        digits[digits.size() - 1] += 1;
        c = digits[digits.size() - 1] / 10;
        digits[digits.size() - 1] %= 10;
        for(int i = digits.size() - 2; i >= 0; i--)
        {
            digits[i] += c;
            c = digits[i] / 10;
            digits[i] %= 10;
        }
        if(c == 0)
        {
            return digits;
        }
        else
        {
            vector<int> res = {1};
            res.insert(res.end(), digits.begin(), digits.end());
            return res;
        }
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> test = {1, 9};
    auto res = s.plusOne(test);
    for(auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
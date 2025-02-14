/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */
#include <string>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        char c = 0;
        string res;
        int max = a.size() > b.size() ? a.size() : b.size();
        for(int i = 1; i <= max; i++)
        {
            char p1 = (int)a.size() - i >= 0 ? a[a.size() - i] - '0' : 0;
            char p2 = (int)b.size() - i >= 0 ? b[b.size() - i] - '0': 0;
            char sum = p1 + p2 + c;
            c = sum / 2;
            sum = sum % 2 + '0';
            res = sum + res;
        }
        if(c)
        {
            res = '1' + res;
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.addBinary("11", "1") << endl;
    return 0;
}
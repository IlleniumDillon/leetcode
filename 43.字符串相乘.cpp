/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */
#include <string>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string add(string a, string b)
    {
        char c = 0;
        string res;
        int max = a.size() > b.size() ? a.size() : b.size();
        for(int i = 1; i <= max; i++)
        {
            char p1 = (int)a.size() - i >= 0 ? a[a.size() - i] - '0' : 0;
            char p2 = (int)b.size() - i >= 0 ? b[b.size() - i] - '0': 0;
            char sum = p1 + p2 + c;
            c = sum / 10;
            sum = sum % 10 + '0';
            res = sum + res;
        }
        if(c)
        {
            res = '1' + res;
        }
        return res;
    }
    string mul(string a, char b)
    {
        string res;
        if(b == '0') return "0";
        char c = 0;
        for(int i = a.size()-1; i >=0; i--)
        {
            char m = (a[i] - '0') * (b - '0') + c;
            c = m / 10;
            m = (m % 10) + '0';
            res = m + res;
        }
        if(c)
        {
            c += '0';
            res = c + res;
        }
        return res;
    }
    string multiply(string num1, string num2) {
        string res = "";
        if(num1.size() < num2.size())
        {
            res = num1;
            num1 = num2;
            num2 = res;
        }
        res = "";
        reverse(num2.begin(), num2.end());
        while(!num2.empty())
        {
            res.push_back('0');
            res = add(res, mul(num1, num2[num2.size() - 1]));
            num2.pop_back();
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.multiply("123", "0") << endl;
    return 0;
}
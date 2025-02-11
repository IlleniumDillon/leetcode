/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include <string>
#include <map>
#include <iostream>

using namespace std;
// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        multimap<int, char> m;
        if (numRows == 1) return s;
        int row = 0;
        int col = 0;
        int i = 0;
        while(i < s.size())
        {
            for(int j = 0; j < numRows; j++)
            {
                if(i >= s.size()) break;
                m.insert(make_pair(row*1000 + col, s[i]));
                row++;
                i++;
            }
            row-=2;
            col++;
            for(int j = 0; j < numRows - 2; j++)
            {
                if(i >= s.size()) break;
                m.insert(make_pair(row*1000 + col, s[i]));
                row--;
                col++;
                i++;
            }
        }
        string res;
        for(auto p : m)
        {
            res.push_back(p.second);
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.convert("AB", 1);
    return 0;
}
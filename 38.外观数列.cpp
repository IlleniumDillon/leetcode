/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */
#include <string>
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    void getStr(string& s)
    {
        vector<pair<char,int>> dist;
        for(int i = 0; i < s.size(); i++)
        {
            if(dist.empty())
            {
                dist.push_back(make_pair(s[i], 1));
                continue;
            }

            if(dist[dist.size() - 1].first == s[i])
            {
                dist[dist.size() - 1].second++;
            }
            else
            {
                dist.push_back(make_pair(s[i], 1));
            }
        }
        s.clear();
        for(int i = 0; i < dist.size(); i++)
        {
            s.push_back('0' + dist[i].second);
            s.push_back(dist[i].first);
        }
    }
    string countAndSay(int n) {
        string res = "1";
        for(;n > 1; n--)
        {
            getStr(res);
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.countAndSay(4) << endl;
    return 0;
}
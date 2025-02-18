/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
    bool res = false;
public:
    void subFun(string s, string p, char pre)
    {
        if(s.empty() && p.empty())
        {
            res = true;
            return;
        }
        else if(s.empty() || p.empty())
        {
            return;
        }

        if(p.back() == '.')
        {
            s.pop_back();
            char q = p.back();
            p.pop_back();
            subFun(s,p,q);
        }
        else if(p.back() == '*')
        {
            if(pre == '.')
            {
                while(!s.empty())
                {
                    s.pop_back();
                    subFun(s,p,pre);
                }
                char q = p.back();
                p.pop_back();
                subFun(s,p,q);
            }
            else
            {
                while(!s.empty())
                {
                    if(s.back()!=pre) break;
                    s.pop_back();
                    subFun(s,p,pre);
                }
                char q = p.back();
                p.pop_back();
                subFun(s,p,q);
            }
        }
        else if(s.back() != p.back())
        {
            int i = p.size() - 1;
            if(i-1>0 && p[i-1]=='*')
            {
                char q = p.back();
                p.pop_back();
                subFun(s,p,q);
            }
            else
            {
                return;
            }
        }
        else
        {
            s.pop_back();
            char q = p.back();
            p.pop_back();
            subFun(s,p,q);
        }
    }
    bool isMatch(string s, string p) {
        reverse(s.begin(),s.end());
        reverse(p.begin(),p.end());
        subFun(s,p,0);
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.isMatch("aaa","a*a") << endl;
    return 0;
}
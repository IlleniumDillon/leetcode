/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    void seed(vector<string>& res, string prifix, bool b, int max, int left)
    {
        if(left < 0) return; 
        if(max == prifix.size() && left == 0)
        {
            res.push_back(prifix);
            return ;
        }
        else if(max == prifix.size() && left != 0)
        {
            return;
        }
        // if(b)
        // {
        //     seed(res, prifix + "(", true, max, left+1);
        //     seed(res, prifix + "(", false, max, left+1);
        // }
        // else
        // {
        //     seed(res, prifix + ")", true, max, left-1);
        //     seed(res, prifix + ")", false, max, left-1);
        // }
        seed(res, prifix + "(", true, max, left+1);
        seed(res, prifix + ")", false, max, left-1);
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        seed(res, "", true, n*2, 0);
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    auto res = s.generateParenthesis(13);
    for(auto i : res)
    {
        cout << i << endl;
    }
    return 0;
}
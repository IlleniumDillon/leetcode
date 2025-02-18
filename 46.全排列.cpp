/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    void subfun(vector<vector<int>>& res, vector<int>& prefix, vector<int>& left_num)
    {
        if(left_num.size() == 0)
        {
            res.push_back(prefix);
        }

        for(int i = 0; i < left_num.size(); i++)
        {
            vector<int> prefix_ = prefix;
            vector<int> left_num_ = left_num;
            prefix_.push_back(left_num_[i]);
            left_num_.erase(left_num_.begin() + i);
            subfun(res, prefix_, left_num_);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> prefix;
        subfun(res, prefix, nums);
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> test = {1};
    auto res = s.permute(test);
    for(auto i : res)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return  0;
}
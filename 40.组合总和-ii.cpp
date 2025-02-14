/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    void subfun(vector<vector<int>>& res, vector<int> prefix, vector<int> candidates, int target)
    {
        if(target<0) return;
        else if(target == 0)
        {
            res.push_back(prefix);
            return;
        }
        if(candidates.empty()) return;
        for(int i = 0; i < candidates.size(); )
        {
            if(candidates[i] > target) break;
            int j = 1;
            for(; i + j < candidates.size(); j++)
            {
                if(candidates[i] != candidates[i + j]) break;
            }
            vector<int> t = prefix;
            for(int k = 0; k < j; k++)
            {
                t.push_back(candidates[i]);
                subfun(res, t, vector<int>(candidates.begin() + i + j, candidates.end()), target - candidates[i] * (k + 1));
            }
            i += j;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        subfun(res, {}, candidates, target);
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> test = {2,5,2,1,2};
    auto res = s.combinationSum2(test, 15);
    for(auto i : res)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include <vector>
#include <algorithm>
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
        for(int i = 0; i < candidates.size(); i++)
        {
            vector<int> t = prefix;
            t.push_back(candidates[i]);
            subfun(res, t, vector<int>(candidates.begin()+i, candidates.end()), target-candidates[i]);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        subfun(res, {}, candidates, target);
        // for(int i = 0; i < candidates.size(); i++)
        // {
        //     subfun(res, {candidates[i]}, vector<int>(candidates.begin()+i, candidates.end()), target-candidates[i]);
        // }
        return res;
    }
};
// @lc code=end


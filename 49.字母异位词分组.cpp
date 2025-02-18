/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include <vector>
#include <unordered_set>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<string> key;
        for(int i = 0; i < strs.size(); i++)
        {
            string k = strs[i];
            sort(k.begin(), k.end());
            if(res.size() == 0) 
            {
                vector<string> newV;
                newV.push_back(strs[i]);
                res.push_back(newV);
                
                key.push_back(k);
                continue;
            }
            int indx = -1;
            for(int j = 0; j < key.size(); j++)
            {
                if(key[j] == k)
                {
                    res[j].push_back(strs[i]);
                    indx = j;
                    break;
                }
            }
            if(indx == -1)
            {
                vector<string> newV;
                newV.push_back(strs[i]);
                res.push_back(newV);
                key.push_back(k);
            }
        }
        return res;
    }
};
// @lc code=end


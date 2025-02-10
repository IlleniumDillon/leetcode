/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1) return strs[0];

        int minLen = numeric_limits<int>::max();
        int indx = 0;
        string comp;

        for(int i = 0; i < strs.size(); i++) {
            if(strs[i].size() < minLen) {
                minLen = strs[i].size();
                indx = i;
            }
        }
        comp = strs[indx];

        string res = "";
        if(minLen == 0) return res;
        for(int i = 0; i < minLen; i++) {
            for(int j = 0; j < strs.size(); j++) {
                if(strs[j][i] != comp[i]) {
                    return res;
                }
            }
            res.push_back(comp[i]);
        }
        return res;
    }
};
// @lc code=end


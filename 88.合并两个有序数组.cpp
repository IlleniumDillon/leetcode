/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(;n>0;n--)
        {
            nums1[m+n-1] = nums2[n-1];
        }
        sort(nums1.begin(), nums1.end());
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {(int)nums.size(), (int)nums.size()};
        int l = 0;
        int h = nums.size() - 1;
        int m = nums.size();
        while(l <= h)
        {
            m = (l + h) / 2;
            if(nums[m] >= target)
            {
                h = m - 1;
                res[0] = m;
            }
            else
            {
                l = m + 1;
            }
        }
        if(res[0] < 0 || res[0] >= nums.size() || nums[res[0]] != target) 
            return {-1, -1};
        l = res[0]; h = nums.size() - 1;
        m = nums.size();
        while(l <= h)
        {
            m = (l + h) / 2;
            if(nums[m] > target)
            {
                h = m - 1;
                res[1] = m;
            }
            else
            {
                l = m + 1;
            }
        }
        res[1]--;
        if(res[1] < 0 || res[1] >= nums.size() || nums[res[1]] != target || res[0] > res[1]) 
            return {-1, -1};
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> test = {};
    auto res = s.searchRange(test, 1);
    for(auto i : res)
    {
        cout << i << " " << endl;
    }
    return 0;
}
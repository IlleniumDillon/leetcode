/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0; 
        int h = nums.size() - 1;
        // int ans;
        while(l <= h)
        {
            int m = (l + h) / 2;
            if(nums[m] > target)
            {
                h = m - 1;
            }
            else if(nums[m] < target)
            {
                l = m + 1;
            }
            else
            {
                return m;
            }
        }
        if(l > h)
        {
            return l;
        }
        else
        {
            return h;
        }
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> test = {1,3,5,6};
    cout << s.searchInsert(test, 0) << endl;
    return 0;
}
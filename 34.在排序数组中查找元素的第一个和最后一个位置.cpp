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
        vector<int> res = {-1, -1};
        int l = 0;
        int h = nums.size() - 1;
        int m;
        while(l <= h)
        {
            m = (l + h) / 2;
            if(m == nums.size() - 1)
            {
                return res;
            }
            if(nums[m+1] > target)
            {
                h = m - 1;
            }
            else if (nums[m + 1] < target)
            {
                l = m + 1;
            }
            else
            {
                if(nums[m] == target)
                {
                    h = m - 1;
                }
                else
                {
                    res[0] = m + 1;
                    break;
                }
            }
        }
        // res.push_back(m);
        if(res[0] == -1 ) return res;
        l = 0; h = nums.size() - 1;
        while(l <= h)
        {
            m = (l + h) / 2;
            if()
            if(nums[m-1] > target)
            {
                h = m - 1;
            }
            else if (nums[m - 1] < target)
            {
                l = m + 1;
            }
            else
            {
                if(nums[m] == target)
                {
                    l = m + 1;
                }
                else
                {
                    res[1] = m - 1;
                    break;
                }
            }
        }
        // res.push_back(m);
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> test = {1};
    auto res = s.searchRange(test, 0);
    for(auto i : res)
    {
        cout << i << " " << endl;
    }
    return 0;
}
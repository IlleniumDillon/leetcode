/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {

        int l = 0; int h = nums.size()-1; int m;
        while(l <= h)
        {
            m = (l+h) / 2;
            if(nums[m] == target) return m;
            if(nums[l] < nums[m] && nums[m] > nums[h])
            {
                if(target <= nums[m] && target >= nums[l])
                {
                    h = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
            else if(nums[l] > nums[m] && nums[m] < nums[h])
            {
                if(target >= nums[m] && target <= nums[h])
                {
                    l = m + 1;
                }
                else
                {
                    h = m - 1;
                }
            }
            else if(nums[l] > nums[h])
            {
                if(target > nums[m])
                {
                    h = m - 1;
                }
                else if(target < nums[m])
                {
                    l = m + 1;
                }
                else
                {
                    return m;
                }
            }
            else
            {
                if(target > nums[m])
                {
                    l = m + 1;
                }
                else if(target < nums[m])
                {
                    h = m - 1;
                }
                else
                {
                    return m;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> test = {3,5,1};
    cout << s.search(test, 5);
    return 0;
}
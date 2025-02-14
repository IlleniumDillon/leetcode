/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int offset = 0;
        if(nums.size() <= 1) return nums.size();
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i - 1] == nums[i])
            {
                offset++;
            }
            nums[i - offset] = nums[i];
        }
        return nums.size() - offset;
    }
};
// @lc code=end


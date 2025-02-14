/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int offset = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            nums[i - offset] = nums[i];
            if(nums[i] == val)
            {
                offset++;
            }
        }
        return nums.size()-offset;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> test = {0,1,2,2,3,0,4,2};
    int res = s.removeElement(test, 2);
    cout << res << endl;
    for(int i = 0; i < res; i++)
    {
        cout << test[i] << " ";
    }
    cout << endl;
    return 0;
}
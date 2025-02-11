/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 10e5;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            int p1 = i + 1;
            int p2 = nums.size() - 1;
            int sum;
            while(p1<p2)
            {
                sum = nums[i] + nums[p1] + nums[p2];
                if(abs(target-res) > abs(target-sum)) res = sum;
                if(sum == target)
                {
                    return target;
                }
                else if (sum > target)
                {
                    p2 --;
                }
                else
                {
                    p1 ++;
                }
            }
            // if(abs(target-res) > abs(target-sum)) res = sum;
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> test = {2,3,8,9,10};
    cout << s.threeSumClosest(test, 16);
    return 0;
}
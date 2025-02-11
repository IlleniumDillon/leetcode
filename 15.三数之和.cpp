/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            int j;
            int p1 = i + 1;
            int p2 = nums.size() - 1;
            while(p1<p2)
            {
                if(nums[i] + nums[p1] + nums[p2] == 0)
                {
                    res.push_back({nums[i], nums[p1], nums[p2]});
                    for(j = p1; j < nums.size(); j++)
                    {
                        if(nums[j] != nums[p1]) break;
                    }
                    p1 = j;
                    for(j = p2; j > p1; j--)
                    {
                        if(nums[j] != nums[p2]) break;
                    }
                    p2 = j;
                }
                else if (nums[i] + nums[p1] + nums[p2] > 0)
                {
                    p2 --;
                }
                else
                {
                    p1 ++;
                }
            }

            for(j = i; j < nums.size(); j++)
            {
                if(nums[i] != nums[j]) break;
            }
            i = j - 1;
        }
        return res;
    }
};
// @lc code=end

int main()
{
    vector<int> test = {0,0,0};
    Solution s;
    auto res = s.threeSum(test);
    for(auto r : res)
    {
        for(auto i : r)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int k;
        for(int i = 0; i < nums.size(); i++)
        {
            // int sum3 = target - nums[i];
            for(int j = i+1; j < nums.size(); j++)
            {
                int p1 = j + 1;
                int p2 = nums.size() - 1;
                while(p1<p2)
                {
                    long sum = (long)target - (long)nums[i] - (long)nums[j] - (long)nums[p1] - (long)nums[p2];
                    if(sum == 0)
                    {
                        res.push_back({nums[i], nums[j], nums[p1], nums[p2]});
                        for(k = p1; k < nums.size(); k++)
                        {
                            if(nums[k] != nums[p1])
                            {
                                break;
                            }
                        }
                        p1 = k;
                        for(k = p2; k >= 0; k --)
                        {
                            if(nums[k] != nums[p2])
                            {
                                break;
                            }
                        }
                        p2 = k;
                    }
                    else if(sum < 0)
                    {
                        for(k = p2; k >= 0; k --)
                        {
                            if(nums[k] != nums[p2])
                            {
                                break;
                            }
                        }
                        p2 = k;
                    }
                    else
                    {
                        for(k = p1; k < nums.size(); k++)
                        {
                            if(nums[k] != nums[p1])
                            {
                                break;
                            }
                        }
                        p1 = k;
                    }
                }
                for(k = j; k < nums.size(); k++)
                {
                    if(nums[k] != nums[j])
                    {
                        break;
                    }
                }
                j = k - 1;
            }
            for(k = i; k < nums.size(); k++)
            {
                if(nums[k] != nums[i])
                {
                    break;
                }
            }
            i = k - 1;
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> test = {1000000000,1000000000,1000000000,1000000000};
    auto res = s.fourSum(test, 0);
    for(auto i : res)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
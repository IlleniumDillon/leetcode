/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int>::iterator p1;
        vector<int>::iterator p2 = nums.end() - 1;

        while(p2 - 1 >= nums.begin())
        {
            if(*p2 > *(p2 - 1)) break;
            p2--;
        }
        if(p2 == nums.begin())
        {
            sort(nums.begin(), nums.end());
            return;
        }

        p1 = p2;
        sort(p2, nums.end());
        while(*p2 <= *(p1-1)) p2++;
        int temp = *p2;
        *p2 = *(p1-1);
        *(p1-1) = temp;
        sort(p1, nums.end());
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> test = {2,3,1};
    s.nextPermutation(test);
    for(auto i : test)
    {
        cout << i << " ";
    }
    return 0;
}

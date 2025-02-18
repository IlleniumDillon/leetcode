/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */
#include <vector>
#include <iostream>
#include <functional>
using namespace std;
// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tnum = nums1.size() + nums2.size();
        int p1,p2,n1,n2;
        if(tnum%2)
        {
            p1 = tnum/2 + 1;
            p2 = p1;
        }
        else
        {
            p1 = tnum/2;
            p2 = p1 + 1;
        }

        int pp1 = 0, pp2 = 0;
        for(int i = 0; i < p1; i++)
        {
            if(pp1 >= nums1.size())
            {
                n1 = nums2[pp2];
                pp2++;
            }
            else if(pp2 >= nums2.size())
            {
                n1 = nums1[pp1];
                pp1++;
            }
            else if(nums1[pp1] < nums2[pp2])
            {
                n1 = nums1[pp1];
                pp1++;
            }
            else if(nums1[pp1] >= nums2[pp2])
            {
                n1 = nums2[pp2];
                pp2++;
            }
        }
        if(p1 == p2) return n1;
        if(pp1 >= nums1.size())
        {
            n2 = nums2[pp2];
            pp2++;
        }
        else if(pp2 >= nums2.size())
        {
            n2 = nums1[pp1];
            pp1++;
        }
        else if(nums1[pp1] < nums2[pp2])
        {
            n2 = nums1[pp1];
            pp1++;
        }
        else if(nums1[pp1] >= nums2[pp2])
        {
            n2 = nums2[pp2];
            pp2++;
        }
        return (double)(n1 + n2) / 2;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> test1 = {1,2};
    vector<int> test2 = {3,4};
    cout << s.findMedianSortedArrays(test1,test2) << endl;
    return 0;
}
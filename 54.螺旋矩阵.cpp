/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int row = 0;
        int col = 0;
        int row_min = 0;
        int col_min = 0;
        int row_max = matrix.size();
        int col_max = matrix[0].size();

        int dir = 0;

        while(row_min < row_max && col_min < col_max)
        {
            switch(dir)
            {
                case 0:
                {
                    for(col = col_min; col < col_max; col ++)
                    {
                        res.push_back(matrix[row_min][col]);
                    }
                    row_min++;
                    break;                        
                }
                case 1:
                {
                    for(row = row_min; row < row_max; row++)
                    {
                        res.push_back(matrix[row][col_max - 1]);
                    }
                    col_max--;
                    break;                    
                }
                case 2:
                {
                    for(col = col_max - 1; col >= col_min; col--)
                    {
                        res.push_back(matrix[row_max - 1][col]);
                    }
                    row_max--;
                    break;                    
                }
                case 3:
                {
                    for(row = row_max - 1; row >= row_min; row--)
                    {
                        res.push_back(matrix[row][col_min]);
                    }
                    col_min++;
                    break;                    
                }
            }

            dir++;
            dir%=4;
        }

        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<vector<int>> test = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    auto res = s.spiralOrder(test);
    for(auto i : res)
    {
        cout << i << " ";
    }
    return 0;
}
/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int min_row = 0;
        int max_row = matrix.size() - 1;
        int min_col = 0;
        int max_col = matrix[0].size() - 1;

        while(min_row <= max_row && min_col <= max_col)
        {
            for(int i = 0; i < max_col - min_col; i++)
            {
                int temp = matrix[min_row][min_col + i];
                matrix[min_row][min_col + i] = matrix[max_row - i][min_col];
                
                matrix[max_row - i][min_col] = matrix[max_row][max_col - i];
                
                matrix[max_row][max_col - i] = matrix[min_row + i][max_col];
                
                matrix[min_row + i][max_col] = temp;

            }
            min_col++;
            max_col--;
            min_row++;
            max_row--;
        }
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<vector<int>> test = {
        {5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}
    };
    s.rotate(test);
    for(auto i : test)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
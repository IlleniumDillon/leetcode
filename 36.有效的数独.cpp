/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unsigned char row[9][9] = {0};
        unsigned char col[9][9] = {0};
        unsigned char cell[3][3][9] = {0};

        for(char r = 0; r < 9; r++)
        {
            for(char c = 0; c < 9; c++)
            {
                if(board[r][c] == '.') continue;
                char v = board[r][c] - '1';

                row[r][v]++;
                if(row[r][v] > 1) return false;
                col[c][v]++;
                if(col[c][v] > 1) return false;
                cell[r/3][c/3][v]++;
                if(cell[r/3][c/3][v] > 1) return false;
            }
        }

        return true;
    }
};
// @lc code=end


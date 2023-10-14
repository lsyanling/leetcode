
#pragma once

import std;
using namespace std;

class Solution37 {
public:
    bool row[9][9]{};
    bool column[9][9]{};
    bool grid[3][3][9]{};
    void solveSudoku(vector<vector<char>>& board) {
        initial(board);
        solveSudokuRecursive(board, 0, 0);
    }
    void initial(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.')
                    fill(i, j, board[i][j]);
    }
    bool canFill(int i, int j, char ch) {
        return !(row[i][ch - '1'] || column[j][ch - '1'] || grid[i / 3][j / 3][ch - '1']);
    }
    inline void fill(int i, int j, char ch) {
        row[i][ch - '1'] = !row[i][ch - '1'];
        column[j][ch - '1'] = !column[j][ch - '1'];
        grid[i / 3][j / 3][ch - '1'] = !grid[i / 3][j / 3][ch - '1'];
    }
    bool solveSudokuRecursive(vector<vector<char>>& board, int i, int j) {
        if (j == 9) {
            j = 0;
            i++;
            if (i == 9)
                return true;
        }
        if (board[i][j] == '.')
        {
            for (char ch = '1'; ch <= '9'; ch++) {
                if (canFill(i, j, ch)) {
                    fill(i, j, ch);
                    board[i][j] = ch;
                    if (solveSudokuRecursive(board, i, j + 1))
                        return true;
                    fill(i, j, ch);
                    board[i][j] = '.';
                }
            }
        }
        else
            return solveSudokuRecursive(board, i, j + 1);
        return false;
    }
};
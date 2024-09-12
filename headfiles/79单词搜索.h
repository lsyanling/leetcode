
#pragma once

#include "librarys.h"
using namespace std;

class Solution79 {
  public:
    bool exist(vector<vector<char>> &board, string word) {
        auto m = board.size();
        auto n = board[0].size();
        // 找出所有起点
        vector<vector<int>> start;
        for (auto i = 0; i < m; i++)
            for (auto j = 0; j < n; j++)
                if (board[i][j] == word[0])
                    start.push_back({i, j});

        auto s = start.size();
        for (auto i = 0; i < s; i++) {
            // 每个起点搜索
            board[start[i][0]][start[i][1]] = 0;
            if (backtrack(board, word, start[i][0], start[i][1], 1))
                return true;
            board[start[i][0]][start[i][1]] = word[0];
        }
        return false;
    }
    
    bool backtrack(vector<vector<char>> &board, string &word, int i, int j, int k) {
        if (k == word.size())
            return true;
        auto m = board.size();
        auto n = board[0].size();
        if (i + 1 < m && word[k] == board[i + 1][j]) {
            board[i + 1][j] = 0;
            if (backtrack(board, word, i + 1, j, k + 1))
                return true;
            board[i + 1][j] = word[k];
        }
        if (j + 1 < n && word[k] == board[i][j + 1]) {
            board[i][j + 1] = 0;
            if (backtrack(board, word, i, j + 1, k + 1))
                return true;
            board[i][j + 1] = word[k];
        }
        if (i - 1 >= 0 && word[k] == board[i - 1][j]) {
            board[i - 1][j] = 0;
            if (backtrack(board, word, i - 1, j, k + 1))
                return true;
            board[i - 1][j] = word[k];
        }
        if (j - 1 >= 0 && word[k] == board[i][j - 1]) {
            board[i][j - 1] = 0;
            if (backtrack(board, word, i, j - 1, k + 1))
                return true;
            board[i][j - 1] = word[k];
        }
        return false;
    }
};
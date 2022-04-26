//
//  37_SudokuSolver.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/3/17.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class SudokuSolver {
private:
    bool check(std::vector<std::vector<char>>& board, int i, int j, char val) {
        for (int k = 0; k < 9; k ++) if (board[i][k] == val) return false;
        
        for (int k = 0; k < 9; k ++) if (board[k][j] == val) return false;
        
        for (int m = i / 3 * 3; m < (i / 3 + 1) * 3; m ++) {
            for (int n = j / 3 * 3; n < (j / 3 + 1) * 3; n ++) {
                if (board[m][n] == val) return false;
            }
        }
        
        return true;
    }
    
    bool solveSudoku(std::vector<std::vector<char>>& board, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return solveSudoku(board, i + 1, 0);
        if (board[i][j] != '.') return solveSudoku(board, i, j + 1);
        
        for (int c = '1'; c <= '9'; c ++) {
            if (check(board, i, j, c)) {
                board[i][j] = c;
                if (solveSudoku(board, i, j + 1)) return true;
                board[i][j] = '.';
            }
        }
        
        return false;
    }
    
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        solveSudoku(board, 0, 0);
    }
    
    void main() {
        const int n = 9;
        char a[n][n] = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
        };
        
        std::vector<std::vector<char>> board(n, std::vector<char>(n, '.'));
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                board[i][j] = a[i][j];
            }
        }
        
        solveSudoku(board);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                std::cout << board[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
};

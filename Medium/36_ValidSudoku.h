//
//  36_ValidSudoku.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/16.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class ValidSudoku {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // rows
        for (int i = 0; i < 9; i ++) {
            if (!checkValid(board[i])) return false;
        }
        
        //cols
        for (int i = 0; i < 9; i ++) {
            std::vector<char> cols;
            for (int j = 0; j < 9; j ++) {
                cols.push_back(board[j][i]);
            }
            if (!checkValid(cols)) return false;
        }
        
        //boxes
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                std::vector<char> box;
                for (int n = 0; n < 3; n ++) {
                    for (int m = 0; m < 3; m ++) {
                        box.push_back(board[i + n][j + m]);
                    }
                }
                if (!checkValid(box)) return false;
            }
        }
        
        return true;
    }
    
    void main() {
        std::vector<std::vector<char>> board;
        char a[9][9] = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '8', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
        };
//        char a[9][9] = {
//            {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
//            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
//            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
//            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
//            {'4', '.', '.', '8', '.', '3', '.', '.', '.'},
//            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
//            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
//            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
//            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
//        };
        
        for (int i = 0; i < 9; i ++) {
            std::vector<char> temp_board(a[i], a[i] + sizeof(a[i]) / sizeof(char));
            board.push_back(temp_board);
        }
        
//        for (int i = 0; i < 9; i ++) {
//            for (int j = 0; j < 9; j ++) {
//                std::cout << board[i][j] << ' ';
//            }
//            std::cout << std::endl;
//        }
        std::cout << isValidSudoku(board) << std::endl;
    }
    
private:
    bool checkValid(std::vector<char>& subboard) {
        std::set<int> count;
        for (int i = 0; i < 9; i ++) {
            if (subboard[i] != '.') {
                if (count.find(subboard[i]) != count.end()) return false;
                else count.insert(int(subboard[i]));
            }
        }
        
        return true;
    }
};

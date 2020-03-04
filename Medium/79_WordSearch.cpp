//
//  79_WordSearch.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/3/4.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class WordSearch {
private:
    bool move(std::vector<std::vector<char>>& board, int i, int j, int point, const std::string& word) {
        if (board[i][j] != word[point]) return false;
        if (point == word.size() - 1) return true;
        
        char temp = board[i][j];
        board[i][j] = '*';
        bool res = false;
        if (!res && i - 1 >= 0)
            res = move(board, i - 1, j, point + 1, word);
        if (!res && i + 1 < board.size())
            res = move(board, i + 1, j, point + 1, word);
        if (!res && j - 1 >= 0)
            res = move(board, i, j - 1, point + 1, word);
        if (!res && j + 1 < board[0].size())
            res = move(board, i, j + 1, point + 1, word);
        board[i][j] = temp;
        
        return res;
    }
    
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        if (board.size() == 0 || board[0].size() == 0) {
            if (word == "") return true;
            else return false;
        }
        
        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[i].size(); j ++) {
                if (move(board, i, j, 0, word)) return true;
            }
        }
        
        return false;
    }
    
    void main() {
//        const int m = 1, n = 1;
//        char a[m][n] = {
//            {'A'}
//        };
        
        const int m = 3, n = 4;
        char a[m][n] = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
        };
        
        std::vector<std::vector<char>> board(m, std::vector<char>(n, '0'));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                board[i][j] = a[i][j];
            }
        }
        
        std::string word = "ABCB";
        
        std::cout << exist(board, word) << std::endl;
    }
};

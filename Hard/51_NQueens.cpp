//
//  51_NQueens.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/20.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class NQueens {
private:
    void solve(int p, int r, int c, int d, std::vector<std::string> &res) {
        std::vector<std::string> ans;
    }
    
public:
    int n;
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> res;
        std::vector<std::string> ans;
        this->n = n;
        
        
        return res;
    }
    
    void main() {
        int n = 4;
        std::vector<std::vector<std::string>> res = solveNQueens(n);
        for (int i = 0; i < res.size(); i ++) {
            for (int j = 0; j < res[i].size(); j ++) {
                std::cout << res[i][j] << std::endl;
            }
            std::cout << std::endl;
        }
    }
};

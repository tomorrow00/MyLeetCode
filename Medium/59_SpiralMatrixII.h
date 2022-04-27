//
//  59_SpiralMatrixII.h
//  LeetCode
//
//  Created by 王尚 on 2019/2/24.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class SpiralMatrixII {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));
        
        int lb = 0, rb = n - 1, ub = 0, db = n - 1;
        int direction = 0, num = 1;
        int col = 0, row = 0;
        while (lb <= rb && ub <= db) {
            switch (direction) {
                case 0:
                    res[row][col] = num;
                    if (col >= rb) {
                        direction = 1;
                        ub ++;
                        row ++;
                    }
                    else {
                        col ++;
                    }
                    num ++;
                    break;
                case 1:
                    res[row][col] = num;
                    if (row >= db) {
                        direction = 2;
                        rb --;
                        col --;
                    }
                    else {
                        row ++;
                    }
                    num ++;
                    break;
                case 2:
                    res[row][col] = num;
                    if (col <= lb) {
                        direction = 3;
                        db --;
                        row --;
                    }
                    else {
                        col --;
                    }
                    num ++;
                    break;
                case 3:
                    res[row][col] = num;
                    if (row <= ub) {
                        direction = 0;
                        lb ++;
                        col ++;
                    }
                    else {
                        row --;
                    }
                    num ++;
                    break;
                default:
                    break;
            }
        }
        
        return res;
    }
    
    void main() {
        int n = 4;
        std::vector<std::vector<int>> res = generateMatrix(n);
        for (int i = 0; i < res.size(); i ++) {
            for (int j = 0; j < res[i].size(); j ++) {
                std::cout << res[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
};

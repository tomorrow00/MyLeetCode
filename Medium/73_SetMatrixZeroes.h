//
//  73_SetMatrixZeroes.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/27.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

using namespace std;

class SetMatrixZeroes {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int m = static_cast<int>(matrix.size()), n = static_cast<int>(matrix[0].size());
        bool row = false, col = false;
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) row = true;
                    if (j == 0) col = true;
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                if (matrix[0][j] == 0) matrix[i][j] = 0;
                if (matrix[i][0] == 0) matrix[i][j] = 0;
            }
        }
        
        if (row) for (int i = 0; i < n; i ++) matrix[0][i] = 0;
        if (col) for (int i = 0; i < m; i ++) matrix[i][0] = 0;
    }
    
    void main() {
        const int m = 3, n = 4;
        int a[m][n] = {
            {0, 1, 2, 0},
            {3, 4, 5, 2},
            {1, 3, 1, 5}
        };
        
        std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 0));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                matrix[i][j] = a[i][j];
            }
        }
        
        setZeroes(matrix);
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                std::cout << matrix[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
};

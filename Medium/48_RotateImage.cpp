//
//  48_RotateImage.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/20.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class RotateImage {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        std::reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); i ++) {
            for (int j = i + 1; j < matrix[i].size(); j ++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    
    void main() {
        const int n = 3;
        int a[n][n] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                matrix[i][j] = a[i][j];
            }
        }
        
        rotate(matrix);
        for (int i = 0; i < matrix.size(); i ++) {
            for (int j = 0; j < matrix[i].size(); j ++) {
                std::cout << matrix[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
};

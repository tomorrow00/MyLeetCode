//
//  54_SpiralMatrix.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/20.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class SpiralMatrix {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector <int> res;
        int rowSize = static_cast<int>(matrix.size());
        if (rowSize==0) return res;
        int colSize = static_cast<int>(matrix[0].size());
        int lb = 0, rb = colSize - 1, ub = 0, db = rowSize - 1;// left bound, right bound, up bound, down bound;
        int direction = 0;
        int col = 0, row = 0;
        while (lb <= rb && ub <= db){
            res.push_back(matrix[row][col]);
            switch (direction){
                case 0:  //  right
                    if (col>=rb) {direction = 1;row=row+1;ub++;} else col=col+1;
                    break;
                case 1: // down
                    if (row>=db) {direction = 2;col=col-1;rb--;} else row=row+1;
                    break;
                case 2: // left
                    if (col<=lb) {direction = 3;row=row-1;db--;} else col=col-1;
                    break;
                default:  // up
                    if (row<=ub) {direction = 0;col=col+1;lb++;} else row=row-1;
            }
        }
        return res;
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
        
        std::vector<int> res = spiralOrder(matrix);
        for (int i = 0; i < res.size(); i ++) {
            std::cout << res[i] << ' ';
        }
        std::cout << std::endl;
    }
};

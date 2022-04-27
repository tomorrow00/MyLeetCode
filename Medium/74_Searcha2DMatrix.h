//
//  74_Searcha2DMatrix.h
//  LeetCode
//
//  Created by 王尚 on 2019/2/27.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

using namespace std;

class Searcha2DMatrix {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int low = 0, high = static_cast<int>(matrix.size()) - 1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            if (target == matrix[mid][0]) return true;
            else if (target > matrix[mid][0]) low = mid + 1;
            else high = mid - 1;
        }
        
        if (low == 0) return false;
        
        int mark = low - 1;
        low = 0;
        high = static_cast<int>(matrix[mark].size()) - 1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            if (target == matrix[mark][mid]) return true;
            else if (target > matrix[mark][mid]) low = mid + 1;
            else high = mid - 1;
        }
        
        return false;
    }
    
    void main() {
        const int m = 3, n = 4;
        int a[m][n] = {
            {1, 3, 5, 7},
            {10, 11, 16, 20},
            {23, 30, 34, 50}
        };
        
        std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 0));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                matrix[i][j] = a[i][j];
            }
        }
        
        int target = 0;
        std::cout << searchMatrix(matrix, target) << std::endl;
    }
};

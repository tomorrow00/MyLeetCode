//
//  64_MinimumPathSum.h
//  LeetCode
//
//  Created by 王尚 on 2019/2/26.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

using namespace std;

class MinimumPathSum {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int m = static_cast<int>(grid.size()), n = static_cast<int>(grid[0].size());
        std::vector<std::vector<int>> score(m, std::vector<int>(n, 0));
        score[0][0] = grid[0][0];
        for (int i = 1; i < m; i ++) {
            score[i][0] = grid[i][0] + score[i - 1][0];
        }
        for (int i = 1; i < n; i ++) {
            score[0][i] = grid[0][i] + score[0][i - 1];
        }
        
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                score[i][j] = grid[i][j] + std::min(score[i - 1][j], score[i][j - 1]);
            }
        }
        
        return score[m - 1][n - 1];
    }
    
    void main() {
        const int n = 3;
        int a[n][n] = {
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
        };
        
        std::vector<std::vector<int>> grid(n, std::vector<int>(n, 0));
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                grid[i][j] = a[i][j];
            }
        }
        
        std::cout << minPathSum(grid) << std::endl;
    }
};

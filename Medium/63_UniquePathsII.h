//
//  63_UniquePathsII.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/26.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

using namespace std;

class UniquePathsII {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        int m = static_cast<int>(obstacleGrid.size()), n = static_cast<int>(obstacleGrid[0].size());
        std::vector<int> step(n, 0);
        for (int i = 0; i < n; i ++) {
            if (obstacleGrid[0][i] == 0) step[i] = 1;
            else break;
        }
        
        for (int i = 1; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (obstacleGrid[i][j] == 1) step[j] = 0;
                else {
                    if (j == 0) continue;
                    else step[j] += step[j - 1];
                }
            }
        }
        
        return step[n - 1];
    }
    
    void main() {
        int m = 30, n = 30;
        std::vector<std::vector<int>> obstacleGrid(m, std::vector<int>(n, 0));
        obstacleGrid[1][1] = 1;
        std::cout << uniquePathsWithObstacles(obstacleGrid) << std::endl;
    }
};

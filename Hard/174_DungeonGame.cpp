//
//  174_DungeonGame.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/8/25.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class DungeonGame {
public:
    int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
        if (dungeon.empty()) return 1;
        const uint8_t m = dungeon.size();
        const uint8_t n = dungeon[0].size();
        std::vector<int> hp(n + 1, INT16_MAX);
        hp[n - 1] = 1;
        
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                hp[j] = std::max(1, std::min(hp[j + 1], hp[j]) - dungeon[i][j]);
            }
        }
        
        return hp[0];
    }
    
    void main() {
        const int n = 3;
        int a[n][n] = {
            {-2, -3, 3},
            {-5, -10, 1},
            {10, 30, -5}
        };
        
        std::vector<std::vector<int>> dungeon(n, std::vector<int>(n, 0));
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                dungeon[i][j] = a[i][j];
            }
        }
        std::cout << calculateMinimumHP(dungeon) << std::endl;
    }
};

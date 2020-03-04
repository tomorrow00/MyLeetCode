//
//  70_ClimbingStairs.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/26.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class ClimbingStairs {
public:
    int climbStairs(int n) {
        std::vector<int> stair;
        for (int i = 0; i <= n; i ++) {
            if (i == 0 || i == 1) stair.push_back(1);
            else stair.push_back(stair[i - 1] + stair[i - 2]);
        }
        return stair[n];
    }
    
    void main() {
        int n = 2;
        std::cout << climbStairs(n) << std::endl;
    }
};

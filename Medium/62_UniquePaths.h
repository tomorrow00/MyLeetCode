//
//  62_UniquePaths.h
//  LeetCode
//
//  Created by 王尚 on 2019/2/26.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class UniquePaths {
public:
    int uniquePaths(int m, int n) {
        std::vector<int> step(n, 1);
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                step[j] += step[j - 1];
            }
        }
        
        return step[n - 1];
    }
    
    void main() {
        int m = 3, n = 7;
        std::cout << uniquePaths(m, n) << std::endl;
    }
};

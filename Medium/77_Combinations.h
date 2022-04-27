//
//  77_Combinations.h
//  LeetCode
//
//  Created by 王尚 on 2019/2/28.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class Combinations {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> res;
        int i = 0;
        std::vector<int> temp(k, 0);
        while (i >= 0) {
            temp[i] ++;
            if (temp[i] > n) i --;
            else if (i == k - 1) res.push_back(temp);
            else {
                i ++;
                temp[i] = temp[i - 1];
            }
        }
        
        return res;
    }
    
    void main() {
        int n = 4, k = 2;
        
        std::vector<std::vector<int>> res = combine(n, k);
        for (int i = 0; i < res.size(); i ++) {
            for (int j = 0; j < res[i].size(); j ++) {
                std::cout << res[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
};

//
//  89_GrayCode.h
//  LeetCode
//
//  Created by 王尚 on 2019/3/7.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class GrayCode {
public:
    std::vector<int> grayCode(int n) {
        std::vector<int> res;
        
        for (int i = 0; i < std::pow(2, n); i ++) {
            res.push_back(i ^ (i >> 1));
        }
        
        return res;
    }
    
    void main() {
        int n = 2;
        
        std::vector<int> res = grayCode(n);
        for (int i = 0; i < res.size(); i ++) {
            std::cout << res[i] << ' ';
        }
        std::cout << std::endl;
    }
};

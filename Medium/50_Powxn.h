//
//  50_Powxn.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/20.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class Powxn {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (n == 0) return x;
        if (n == -1) return 1 / x;
        
        return myPow(x * x, n / 2) * (n % 2 == 0 ? 1 : n > 0 ? x : 1 / x);
    }
    
    void main() {
        double x = 2.0000;
        int n = 10;
        std::cout << myPow(x, n) << std::endl;
    }
};

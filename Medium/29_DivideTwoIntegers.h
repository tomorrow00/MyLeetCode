//
//  29. Divide Two Integers 29. Divide Two Integers 29.h
//  LeetCode
//
//  Created by 王尚 on 2018/11/26.
//  Copyright © 2018 tomorrow. All rights reserved.
//

#include "header.h"

class DivideTwoIntegers {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int res = 0;
        while (dvd >= dvs) {
            long long temp = dvs, times = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                times <<= 1;
            }
            dvd -= temp;
            res += times;
        }
        
        return res *= sign;
    }
    
    void main() {
        int dividend = -7, divisor = 3;
        std::cout << divide(dividend, divisor) << std::endl;
    }
};

//
//  69_Sqrtx.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/26.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

using namespace std;

class Sqrtx {
public:
    int mySqrt(int x) {
        int r = x;
        while (r * r > x) {
            r = (r + x / r) / 2;
        }
        return r;
        
//        if (x < 2) return x;
//        long long low = 0, high = x, mid;
//        while (low < high) {
//            mid = (low + high) / 2;
//            if (mid * mid == x) return mid;
//            else if (mid * mid > x) high = mid;
//            else low = mid + 1;
//        }
//
//        return high - 1;
    }
    
    void main() {
        int x = 3;
        std::cout << mySqrt(x) << std::endl;
    }
};

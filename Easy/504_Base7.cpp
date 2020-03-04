//
//  504_Base7.cpp
//  LeetCode
//
//  Created by 王尚 on 2020/2/19.
//  Copyright © 2020 tomorrow. All rights reserved.
//

#include "header.h"

class Base7 {
public:
    std::string convertToBase7(int num) {
        std::string res;
        if (num < 0) {
            res = "-";
            num = -num;
        }
        
        if (num < 7) {
            res += std::to_string(num);
        }
        else {
            res += convertToBase7(num / 7) + std::to_string(num % 7);
        }
        
        return res;
    }
    
    void main() {
        int num = 6;
        std::cout << convertToBase7(num) << std::endl;
    }
};

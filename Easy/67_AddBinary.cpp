//
//  67_AddBinary.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/26.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class AddBinary {
public:
    std::string addBinary(std::string a, std::string b) {
        if (a.size() < b.size()) return addBinary(b, a);
        
        int carry = 0, i = a.size() - 1, j = b.size() - 1;
        
        while (i >= 0 || j >= 0) {
            carry += i >= 0 ? a[i] - '0' : 0;
            carry += j >= 0 ? b[j --] - '0' : 0;
            a[i --] = carry % 2 + '0';
            carry /= 2;
        }
        if (carry == 1) a = char(carry % 2 + '0') + a;
        
        return a;
    }
    
    void main() {
        std::string a = "1010", b = "11";
        std::cout << addBinary(a, b) << std::endl;
    }
};

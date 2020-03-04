//
//  66_PlusOne.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/26.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class PlusOne {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        bool carry = true;
        
        for (int i = digits.size() - 1; i >= 0; i --) {
            if (digits[i] == 9 && carry == true) {
                digits[i] = (digits[i] + carry) % 10;
                carry = true;
            }
            else {
                digits[i] += carry;
                carry = false;
            }
        }
        if (carry) digits.insert(digits.begin(), 1);
        
        return digits;
    }
    
    void main() {
        int a[] = {9, 9, 9};
        std::vector<int> digits(a, a + sizeof(a) / sizeof(int));
        std::vector<int> res = plusOne(digits);
        for (int i = 0; i < res.size(); i ++) {
            std::cout << res[i] << ' ';
        }
        std::cout << std::endl;
    }
};

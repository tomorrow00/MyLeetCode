//
//  43_MultiplyStrings.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/18.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class MultiplyStrings {
public:
    std::string multiply(std::string num1, std::string num2) {
        int l1 = num1.size(), l2 = num2.size();
        std::string res(l1 + l2, '0');
        
        for (int i = l1 - 1; i >= 0; i --) {
            int carry = 0;
            for (int j = l2 - 1; j >= 0; j --) {
                int num = (num1[i] - '0') * (num2[j] - '0') + carry + (res[i + j + 1] - '0');
                carry = num / 10;
                res[i + j + 1] = num % 10 + '0';
            }
            res[i] = carry + '0';
        }
        int index = res.find_first_not_of('0');
        
        if (index != std::string::npos) return res.substr(index, res.size() - index);
        return "0";
    }
    
    void main() {
        std::string num1 = "0", num2 = "0";
        std::cout << multiply(num1, num2) << std::endl;
    }
};

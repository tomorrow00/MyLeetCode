//
//  91_DecodeWays.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/3/7.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class DecodeWays {
public:
    int numDecodings(std::string s) {
        if (!s.size() || s.front() == '0') return 0;
        int temp = 1, res = 1;
        
        for (int i = 1; i < s.size(); i ++) {
            if (s[i] == '0') res = 0;
            
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                    res += temp;
                    temp = res - temp;
            }
            else temp = res;
        }
        
        return res;
    }
    
    void main() {
        std::string s = "1010101010";
        std::cout << numDecodings(s) << std::endl;
    }
};

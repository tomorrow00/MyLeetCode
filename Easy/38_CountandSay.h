//
//  38_CountandSay.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/16.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class CountandSay {
public:
    std::string countAndSay(int n) {
        std::string str = "1";
        std::string result = "";
        
        if (n == 1) return str;
        for (int i = 2; i <= n; i ++) {
            int count = 1;
            for (int j = 0; j < str.size(); j ++) {
                if (str[j] == str[j + 1]) {
                    count ++;
                }
                else {
                    char add = '0' + count;
                    result.push_back(add);
                    result.push_back(str[j]);
                    count = 1;
                }
            }
            str = result;
            result = "";
        }
        
        return str;
    }
    
    void main() {
        int n = 5;
        std::cout << countAndSay(n) << std::endl;
    }
};

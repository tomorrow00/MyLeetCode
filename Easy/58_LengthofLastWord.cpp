//
//  58_LengthofLastWord.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/23.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class LengthofLastWord {
public:
    int lengthOfLastWord(std::string s) {
        int last = s.find_last_not_of(' ');
        int count = 0;
        for (int i = last; i >= 0; i --) {
            if (s[i] == ' ') break;
            count ++;
        }
        
        return count;
    }
    
    void main() {
        std::string s = "Hello World";
        std::cout << lengthOfLastWord(s) << std::endl;
    }
};

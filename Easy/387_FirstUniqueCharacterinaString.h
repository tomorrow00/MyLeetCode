//
//  387_FirstUniqueCharacterinaString.cpp
//  LeetCode
//
//  Created by 王尚 on 2020/2/21.
//  Copyright © 2020 tomorrow. All rights reserved.
//

#include "header.h"

class FirstUniqueCharacterinaString {
public:
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> um;
        for (int i = 0;  i < s.length(); i ++) {
            um[s[i]] ++;
        }
        
        for (int i = 0; i < s.length(); i ++) {
            if (um[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
    
    void main() {
        std::string s = "leetcode";
        std::cout << firstUniqChar(s) << std::endl;
    }
};

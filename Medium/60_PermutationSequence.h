//
//  60_PermutationSequence.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/24.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class PermutationSequence {
public:
    std::string getPermutation(int n, int k) {
        k --;
        std::string s = "";
        std::vector<char> back;
        int stair = 1;
        for (int i = 0; i < n; i ++) {
            stair *= (i + 1);
            char temp = i + 1 + '0';
            back.push_back(temp);
        }
        
        int mark = n;
        for (int i = 0; i < n; i ++) {
            stair /= mark;
            s += back[k / stair];
            back.erase(back.begin() + k / stair);
            k %= stair;
            mark --;
        }
        
        return s;
    }
    
    void main() {
        int n = 4, k = 5;
        std::cout << getPermutation(n, k) << std::endl;
    }
};

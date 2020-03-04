//
//  32_LongestValidParentheses.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/28.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class LongestValidParentheses {
public:
    int longestValidParentheses(std::string s) {
        int count = 0, max_count = 0;
        std::stack<int> stk;
        stk.push(-1);
        
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == '(') stk.push(i);
            else {
                stk.pop();
                if (stk.empty()) stk.push(i);
                else max_count = std::max(max_count, i - stk.top());
            }
        }
        
        return max_count;
    }
    
    void main() {
        std::string s = ")()())";
        std::cout << longestValidParentheses(s) << std::endl;
    }
};

//
//  GenerateParentheses.cpp
//  LeetCode
//
//  Created by 王尚 on 2018/11/20.
//  Copyright © 2018 tomorrow. All rights reserved.
//

#include "header.h"

class GenerateParentheses {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        generate(res, "", n, 0);
        
        return res;
    }
    
    void generate(std::vector<std::string> &res, std::string str, int n, int m) {
        if (n == 0 && m == 0) {
            res.push_back(str);
            return;
        }
        
        if (n > 0) generate(res, str + "(", n - 1, m + 1);
        if (m > 0) generate(res, str + ")", n, m - 1);
    }
    
    void main() {
        int n = 5;
        std::vector<std::string> res = generateParenthesis(n);
        
        for (int i = 0; i < res.size(); i ++) {
            std::cout << res[i] << std::endl;
        }
    }
};

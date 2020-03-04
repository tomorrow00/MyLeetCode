//
//  93_RestoreIPAddresses.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/3/9.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class RestoreIPAddresses {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> res;
        
        return res;
    }

    void main() {
        std::string s = "25525511135";
        
        std::vector<std::string> res = restoreIpAddresses(s);
        for (int i = 0; i < res.size(); i ++) {
            std::cout << res[i] << ' ';
        }
        std::cout << std::endl;
    }
};

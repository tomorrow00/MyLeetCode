//
//  71_SimplifyPath.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/26.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class SimplifyPath {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> route;
        std::string temp;
        std::istringstream ss(path);
//        stringstream ss(path);

        while (getline(ss, temp, '/')) {
            if (temp == "" || temp == "." || (temp == ".." && route.empty())) continue;
            else if (temp == "..") {route.pop_back();}
            else route.push_back(temp);
        }
        for (int i = 0; i < route.size(); i ++) {
            std::cout << route[i] << ' ';
        }
        std::cout << std::endl;

        std::string res = route.empty() ? "/" : "";
        for (int i = 0; i < route.size(); i ++) {
            res += "/" + route[i];
        }
        
        return res;
    }
    
    void main() {
        std::string path = "/../";
        std::cout << simplifyPath(path) << std::endl;
    }
};

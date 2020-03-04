//
//  49_GroupAnagrams.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/20.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class GroupAnagrams {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> res;
        std::unordered_map<std::string, std::vector<std::string>> um;
        
        for (auto s : strs) {
            std::string temp = s;
            std::sort(temp.begin(), temp.end());
            um[temp].push_back(s);
        }
        for (auto s : um) {
            res.push_back(s.second);
        }
        
        return res;
    }
    
    void main() {
        std::string a[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
        std::vector<std::string> strs(a, a + sizeof(a) / sizeof(std::string));
        std::vector<std::vector<std::string>> res = groupAnagrams(strs);
        for (int i = 0; i < res.size(); i ++) {
            for (int j = 0; j < res[i].size(); j ++) {
                std::cout << res[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
};

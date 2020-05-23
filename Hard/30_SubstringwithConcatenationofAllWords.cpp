//
//  30_SubstringwithConcatenationofAllWords.cpp
//  LeetCode
//
//  Created by 王尚 on 2018/11/27.
//  Copyright © 2018 tomorrow. All rights reserved.
//

#include "header.h"

class SubstringwithConcatenationofAllWords {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> res;
        std::map<std::string, int> stable;
        std::map<std::string, int> move;
        int n = static_cast<int>(words[0].size());
        
        for (std::string word : words) {
            stable[word] ++;
        }
        
        for (int i = 0; i + n * words.size() <= s.size(); i ++) {
            std::string c = s.substr(i, n);
            std::cout << c << std::endl;
        }
        
        return res;
    }
    
    void main() {
        std::vector<std::string> words;
        std::string s = "barfoothefoobarman";
        
        words.push_back("foo");
        words.push_back("bar");
        
        std::vector<int> res = findSubstring(s, words);
        for (int i = 0; i < res.size(); i ++) {
            std::cout << res[i];
        }
        std::cout << std::endl;
    }
};

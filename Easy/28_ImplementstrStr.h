//
//  28_ImplementstrStr.cpp
//  LeetCode
//  KMP
//
//  Created by 王尚 on 2018/11/23.
//  Copyright © 2018 tomorrow. All rights reserved.
//

#include "header.h"

class StrStr {
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.empty()) return 0;
        if (haystack.empty()) return -1;
        int *table = new int[needle.size()];
        
        table[0] = -1;
        int k = -1, j = 0;
        while (j < needle.size() - 1) {
            if (k == -1 || needle[j] == needle[k]) {
                table[++j] = ++k;
            }
            else k = table[k];
        }
        
        int i = 0;
        j = 0;
        while (i < haystack.size()) {
            if (j == -1 || haystack[i] == needle[j]) {
                i ++;
                j ++;
            }
            else j = table[j];
            if (j == needle.size()) return i - j;
        }
        
        return -1;
    }
    
    void main() {
        std::string haystack = "hello";
        std::string needle = "ll";
        
        int res = strStr(haystack, needle);
        std::cout << res << std::endl;
    }
};

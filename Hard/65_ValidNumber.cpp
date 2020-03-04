//
//  65_ValidNumber.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/26.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class ValidNumber {
public:
    bool isNumber(std::string s) {
        bool e = false, dot = false, sig = false, number = false;
        if (s == "\0") return false;
        char *p = &s[0];
        p = &s[s.find_first_not_of(' ')];
        
        while (*p != '\0') {
            if (*p >= '0' && *p <= '9') {
                sig = true;
                number = true;
                p ++;
            }
            else if (*p == 'e' || *p == 'E') {
                if (e == true || *(p + 1) == '\0' || number == false) return false;
                else {
                    e = true;
                    dot = true;
                    sig = false;
                    number = false;
                    p ++;
                }
            }
            else if (*p == '+' || *p == '-') {
                if (sig == true) return false;
                else {
                    sig = true;
                    p ++;
                }
            }
            else if (*p == '.' && dot == false) {
                if (dot == true) return false;
                else {
                    sig = true;
                    dot = true;
                    p ++;
                }
            }
            else if (*p == ' ') {
                while (*p == ' ') {
                    p ++;
                }
                if (*p == '\0') break;
                else return false;
            }
            else
                return false;
        }
        
        if (number == false) return false;
        else return true;
    }
    
    void main() {
        std::string s = "0";
        std::cout << isNumber(s) << std::endl;
    }
};

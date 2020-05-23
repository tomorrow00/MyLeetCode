//
//  67_AddBinary.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/26.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

using namespace std;

class AddBinary {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) return addBinary(b, a);
        
        int carry = 0, i = static_cast<int>(a.size()) - 1, j = static_cast<int>(b.size()) - 1;
        
        while (i >= 0 || j >= 0) {
            carry += i >= 0 ? a[i] - '0' : 0;
            carry += j >= 0 ? b[j --] - '0' : 0;
            a[i --] = carry % 2 + '0';
            carry /= 2;
        }
        if (carry == 1) a = char(carry % 2 + '0') + a;
        
        return a;
    }
    
    void main() {
        string a = "1010", b = "11";
        cout << addBinary(a, b) << endl;
    }
};

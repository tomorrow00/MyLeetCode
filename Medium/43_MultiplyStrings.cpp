//
//  43_MultiplyStrings.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/18.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

using namespace std;

class MultiplyStrings {
public:
    string multiply(string num1, string num2) {
        int l1 = static_cast<int>(num1.size()), l2 = static_cast<int>(num2.size());
        string res(l1 + l2, '0');
        
        for (int i = l1 - 1; i >= 0; i --) {
            int carry = 0;
            for (int j = l2 - 1; j >= 0; j --) {
                int num = (num1[i] - '0') * (num2[j] - '0') + carry + (res[i + j + 1] - '0');
                carry = num / 10;
                res[i + j + 1] = num % 10 + '0';
            }
            res[i] = carry + '0';
        }
        int index = static_cast<int>(res.find_first_not_of('0'));
        
        if (index != string::npos) return res.substr(index, res.size() - index);
        return "0";
    }
    
    void main() {
        string num1 = "0", num2 = "0";
        cout << multiply(num1, num2) << endl;
    }
};

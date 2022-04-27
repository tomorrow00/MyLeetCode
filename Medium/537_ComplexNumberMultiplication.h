//
//  537_ComplexNumberMultiplication.h
//  LeetCode
//
//  Created by 王尚 on 2021/8/25.
//  Copyright © 2021 tomorrow. All rights reserved.
//

#include "header.h"

#include <ostream>

using namespace std;

class ComplexNumberMultiplication {
public:
    string complexNumberMultiply(string num1, string num2) {
        stringstream aa(num1), bb(num2), res;
        int ra, ia, rb, ib;
        char buff;
        aa >> ra >> buff >> ia >> buff;
        bb >> rb >> buff >> ib >> buff;
        res << ra * rb - ia * ib << '+' << rb * ia + ra * ib << "i";
        
        return res.str();
    }

    void main() {
        string num1 = "1+-1i";
        string num2 = "0+0i";
        cerr << complexNumberMultiply(num1, num2) << endl;
    }
};
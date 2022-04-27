//
//  151_ReverseWordsinaString.h
//  LeetCode
//
//  Created by 王尚 on 2021/10/20.
//  Copyright © 2021 tomorrow. All rights reserved.
//

#include "header.h"

class ReverseWordsinaString {
public:
    string reverseWords(string s) {
        vector<string> vec;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            vec.push_back(word);
        }
        reverse(vec.begin(), vec.end());

        string res;
        for (const auto& v : vec) {
            res += " " + v;
        }
        res.erase(0, 1);

        return res;
    }

    void main() {
        string str = "   the  sky is  blue";
        cout << reverseWords(str) << endl;
    }
};
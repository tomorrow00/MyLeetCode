//
//  96_UniqueBinarySearchTrees.cpp
//  LeetCode
//
//  Created by Tomorrow on 2020/5/22.
//  Copyright © 2020 tomorrow. All rights reserved.
//

#include "header.h"

class UniqueBinarySearchTrees {
public:
    int numTrees(int n) {
        vector<int> res(n + 2, 0);
        res[0] = res[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                res[i] += res[j] * res[i - 1 - j];
            }
        }
        return res[n];
    }

    void main() {
        int n = 1;
        cerr << numTrees(n) << endl;
    }
};
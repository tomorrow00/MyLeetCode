//
//  260_SingleNumberIII.cpp
//  LeetCode
//
//  Created by 王尚 on 2021/11/6.
//  Copyright © 2021 tomorrow. All rights reserved.
//

#include "header.h"
#include "float.h"

class SingleNumberIII {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> um;
        vector<int> res;

        for (const auto& n : nums) {
            um[n] ++;
        }
        for (const auto& n : um) {
            if (n.second == 1) {
                res.push_back(n.first);
            }
        }

        return res;
    }

    void main() {
        vector<int> nums = {-1, 2};
        vector<int> res = singleNumber(nums);
        for (const auto& n : res) {
            cout << n << ' ';
        }
        cout << endl;
    }
};
//
//  27_RemoveElement.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/3/4.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class RemoveElement {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int length = 0;
        // if (nums.size() == 0) return length;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) nums[length++] = nums[i];
        }
        return length;
    }
};

//
//  26_RemoveDuplicatesfromSortedArray.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/3/4.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class RemoveDuplicatesfromSortedArray {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int length = 0;
        if (nums.size() == 0) return length;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums[length]) nums[++length] = nums[i];
        }
        return ++length;
    }
};

//
//  55_JumpGame.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/21.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class JumpGame {
public:
    bool canJump(std::vector<int>& nums) {
        int i = 0;
        
        for (int reach = 0; i < nums.size() && i <= reach; i ++) {
            reach = std::max(i + nums[i], reach);
        }
        
        return i == nums.size();
    }
    
    void main() {
        int a[] = {2, 2, 1, 5, 4};
        std::vector<int> nums(a, a + sizeof(a) / sizeof(int));
        std::cout << canJump(nums) << std::endl;
    }
};

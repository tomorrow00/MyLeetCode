//
//  45_JumpGameII.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/3/1.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class JumpGameII {
public:
    int jump(std::vector<int>& nums) {
        int start = 0, end = 0, maxend = 0, step = 0;
        
        while (maxend < nums.size() - 1) {
            for (int i = start; i <= end; i ++) {
                maxend = std::max(maxend, i + nums[i]);
                if (maxend >= nums.size() - 1) {
                    step ++;
                    return step;
                }
            }
            start = end + 1;
            end = maxend;
            step ++;
        }
        
        return step;
    }
    
    void main() {
        int a[] = {2, 3, 1, 1, 4};
//        int a[] = {5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0};
        std::vector<int> nums(a, a + sizeof(a) / sizeof(int));
        std::cout << jump(nums) << std::endl;
    }
};

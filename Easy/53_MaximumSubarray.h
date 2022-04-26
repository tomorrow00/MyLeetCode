//
//  53_MaximumSubarray.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/20.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class MaximumSubarray {
public:
    int maxSubArray(std::vector<int>& nums) {
        // dp
        int sum = 0, maxsum = nums[0];
        for (int i = 0; i < nums.size(); i ++) {
            sum += nums[i];
            maxsum = maxsum > sum ? maxsum : sum;
            sum = sum > 0 ? sum : 0;
        }
        
        return maxsum;
    }
    
    void main() {
        int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        std::vector<int> nums(a, a + sizeof(a) / sizeof(int));
        std::cout << maxSubArray(nums) << std::endl;
    }
};

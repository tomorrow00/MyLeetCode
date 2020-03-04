//
//  75_SortColors.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/27.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class SortColors {
public:
    void sortColors(std::vector<int>& nums) {
        int l = 0, m = 0, h = 0;
        
        for (auto num : nums) {
            if (num == 0) {
                nums[h ++] = 2;
                nums[m ++] = 1;
                nums[l ++] = 0;
            }
            else if (num == 1) {
                nums[h ++] = 2;
                nums[m ++] = 1;
            }
            else nums[h ++] = 2;
        }
    }
    
    void main() {
        int a[] = {2, 0, 2, 1, 1, 0};
        std::vector<int> nums(a, a + sizeof(a) / sizeof(int));
        
        sortColors(nums);
        for (int i = 0; i < nums.size(); i ++) {
            std::cout << nums[i] << ' ';
        }
        std::cout << std::endl;
    }
};

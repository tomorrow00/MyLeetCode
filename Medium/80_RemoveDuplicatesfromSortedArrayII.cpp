//
//  80_RemoveDuplicatesfromSortedArrayII.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/3/4.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class RemoveDuplicatesfromSortedArrayII {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return nums.size();
        int length = 0, duplicated = 0;
        
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == nums[length] && i != length) {
                if (!duplicated) nums[++ length] = nums[i];
                duplicated ++;
            }
            else if (nums[i] != nums[length]) {
                nums[++ length] = nums[i];
                duplicated = 0;
            }
        }
        
        return ++ length;
    }
    
    void main() {
        int a[] = {0, 0, 1, 1, 1, 1, 2, 3, 3};
        std::vector<int> nums(a, a + sizeof(a) / sizeof(int));
        
        int length = removeDuplicates(nums);
        std::cout << length << std::endl;
        for (int i = 0; i < length; i ++) {
            std::cout << nums[i] << ' ';
        }
        std::cout << std::endl;
    }
};

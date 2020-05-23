//
//  41_FirstMissingPositive.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/17.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class FirstMissingPositive {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        // swap
        for (int i = 0; i < nums.size(); i ++) {
            while (nums[i] > 0 && nums[i] < nums.size() && nums[i] != nums[nums[i] - 1]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] != i + 1) return i + 1;
        }
        
        return static_cast<int>(nums.size()) + 1;
        
        // ilegal sort()
//        if (nums.empty()) return 1;
//
//        std::sort(nums.begin(), nums.end());
//        int num = 0;
//
//        for (int i = 0; i < nums.size(); i ++) {
//            if (nums[i] > 0) {
//                num ++;
//                if (i > 0 && nums[i] == nums[i - 1]) num --;
//                if (num != nums[i]) return num;
//            }
//        }
//
//        return nums[nums.size() - 1] > 0 ? ++nums[nums.size() - 1] : 1;
    }
    
    void main() {
        int a[] = {1,2,3,4,6};
//        int a[] = {7, 8, 9, 11, 12};
        std::vector<int> nums(a, a + sizeof(a) / sizeof(int));
        std::cout << firstMissingPositive(nums) << std::endl;
    }
};

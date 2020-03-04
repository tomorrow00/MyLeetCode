//
//  35_SearchInsertPosition.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/16.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class SearchInsertPosition {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (target == nums[mid]) return mid;
            else if (target < nums[mid]) right = mid - 1;
            else left = mid + 1;
        }
        
        return right + 1;
    }
    
    void main() {
        int target = 7;
        int a[] = {1, 3, 5, 6};
        std::vector<int> nums(a, a + sizeof(a) / sizeof(int));
        
        std::cout << searchInsert(nums, target) << std::endl;
    }
};

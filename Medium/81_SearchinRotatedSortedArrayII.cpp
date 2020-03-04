//
//  81_SearchinRotatedSortedArrayII.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/3/4.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class SearchinRotatedSortedArrayII {
public:
    bool search(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (target == nums[mid]) return true;
            
            if ((nums[left] == nums[mid]) && (nums[right] == nums[mid])) {
                ++ left;
                -- right;
            }
            else if ((nums[mid] < nums[left] && (target >= nums[left] || target <= nums[mid]))
                     || (nums[mid] > nums[left] && (target >= nums[left]  && target <= nums[mid]))
                     || (nums[mid] == nums[left] && (target >= nums[left]  && target <= nums[mid]))) {
                right = mid;
            }
            else left = mid + 1;
            
            if (left > right) return false;
        }
        
        return false;
    }
    
    void main() {
        int a[] = {1, 3, 1, 1, 1};
        std::vector<int> nums(a, a + sizeof(a) / sizeof(int));
        int target = 3;
        
        std::cout << search(nums, target) << std::endl;
    }
};

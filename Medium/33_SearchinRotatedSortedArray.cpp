//
//  33_SearchinRotatedSortedArray.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/15.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class SearchinRotatedSortedArray {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (target == nums[mid]) return mid;
            else if ((nums[mid] < nums[left] && (target >= nums[left] || target <= nums[mid]))
                     || (nums[mid] > nums[left] && (target >= nums[left]  && target <= nums[mid]))) {
                right = mid;
            }
            else left = mid + 1;
            
            if (left > right) return -1;
        }
        
        return -1;
    }
    
    void main() {
        int target = 4;
        int a[] = {4};
        std::vector<int> nums(a, a + sizeof(a) / sizeof(int));
        
        int result = search(nums, target);
        std::cout << result << std::endl;
    }
};

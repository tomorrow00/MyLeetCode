//
//  34_FindFirstandLastPositionofElementinSortedArray.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/15.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class FindFirstandLastPositionofElementinSortedArray {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        std::vector<int> result;
        int left = 0;
        uint8_t right = nums.size() - 1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (target == nums[mid]) {
                left = mid;
                right = mid;
                
                while (left >= 0 && nums[left] == target) {
                    left --;
                }
                while (right < nums.size() && nums[right] == target) {
                    right ++;
                }
                
                result.push_back(++ left);
                result.push_back(-- right);
                
                return result;
            }
            else if (target < nums[mid]) right = mid - 1;
            else left = mid + 1;
        }
        
        if (result.empty()) {
            result.push_back(-1);
            result.push_back(-1);
        }
        
        return result;
    }
    
    void main() {
        int target = 6;
        int a[] = {5, 7, 7, 8, 8, 10};
        std::vector<int> nums(a, a + sizeof(a) / sizeof(int));
        
        std::vector<int> result = searchRange(nums, target);
        for (int i = 0; i < result.size(); i ++) {
            std::cout << result[i] << std::endl;
        }
    }
};

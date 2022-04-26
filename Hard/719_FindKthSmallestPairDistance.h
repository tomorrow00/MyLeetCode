//
//  719_FindKthSmallestPairDistance.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/8/14.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class FindKthSmallestPairDistance {
public:
    int smallestDistancePair(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        
        int low = 0, high = nums.back() - nums[0] + 1;
        while (low < high) {
            int mid = (low + high) / 2;
            int count = 0;
            for (int i = 0, j = 1; i <= j && j < nums.size();) {
                if (nums[j] - nums[i] <= mid) {
                    count += j - i;
                    j ++;
                }
                else {
                    i ++;
                }
            }
            
            if (count >= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        
        return low;
    }
    
    void main() {
        int k = 1;
        int a[] = {1, 3, 1};
        std::vector<int> nums(a, a + sizeof(a) / sizeof(int));
        std::cout << smallestDistancePair(nums, k) << std::endl;
    }
};

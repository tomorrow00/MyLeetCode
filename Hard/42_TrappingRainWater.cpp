//
//  42_TrappingRainWater.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/17.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

using namespace std;

class TrappingRainWater {
public:
    int trap(std::vector<int>& height) {
        int left = 0, right = static_cast<int>(height.size()) - 1, res = 0, level = 0;
        
        while (left <= right) {
            int low = height[height[left] < height[right] ? left ++ : right --];
            level = std::max(level, low);
            res += level - low;
        }
        
        return res;
    }
    
    void main() {
        int a[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        std::vector<int> height(a, a + sizeof(a) / sizeof(int));
        std::cout << trap(height) << std::endl;
    }
};

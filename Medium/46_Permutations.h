//
//  46_Permutations.h
//  LeetCode
//
//  Created by 王尚 on 2019/2/18.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class Permutations {
private:
    void permutations(std::vector<int> nums, int index, std::vector<std::vector<int>>& res) {
        if (index == nums.size()) {
            res.push_back(nums);
            return;
        }
        
        for (int i = index; i < nums.size(); i ++) {
            std::swap(nums[index], nums[i]);
            permutations(nums, index + 1, res);
            std::swap(nums[index], nums[i]);
        }
    }
    
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        permutations(nums, 0, res);
        
        return res;
    }
    
    void main() {
        int a[] = {1, 2, 3};
        std::vector<int> nums(a, a + sizeof(a) / sizeof(int));
        
        std::vector<std::vector<int>> res = permute(nums);
        for (int i = 0; i < res.size(); i ++) {
            for (int j = 0; j < res[i].size(); j ++) {
                std::cout << res[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
};

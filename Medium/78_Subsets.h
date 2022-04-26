//
//  78_Subsets.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/28.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class Subsets {
private:
    void subsets(int pos, std::vector<int> sub, std::vector<int> &nums, std::vector<std::vector<int>> &res) {
        if (pos == nums.size()) return;
        
        for (int i = pos; i < nums.size(); i ++) {
            sub.push_back(nums[i]);
            res.push_back(sub);
            subsets(i + 1, sub, nums, res);
            sub.pop_back();
        }
    }
    
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> res = {{}};
        std::vector<int> sub;
        subsets(0, sub, nums, res);
        
        return res;
    }
    
    void main() {
        int a[] = {1, 2, 3};
        std::vector<int> nums(a, a + sizeof(a) / sizeof(int));
        
        std::vector<std::vector<int>> res = subsets(nums);
        for (int i = 0; i < res.size(); i ++) {
            for (int j = 0; j < res[i].size(); j ++) {
                std::cout << res[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
};

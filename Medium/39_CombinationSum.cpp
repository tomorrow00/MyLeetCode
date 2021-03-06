//
//  39_CombinationSum.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/17.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class CombinationSum {
private:
    void combinationSum(std::vector<int>& candidates, std::vector<int>& temp_result, std::vector<std::vector<int>>& result, int target, int p) {
        for (int i = p; i < candidates.size(); i ++) {
            if (target < candidates[i]) break;
            
            temp_result.push_back(candidates[i]);
            if (target > candidates[i]) {
                target -= candidates[i];
                combinationSum(candidates, temp_result, result, target, i);
                target += candidates[i];
            }
            else result.push_back(temp_result);
            temp_result.pop_back();
        }
    }
    
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> temp_result;
        std::sort(candidates.begin(), candidates.end());
        
        combinationSum(candidates, temp_result, result, target, 0);
        
        return result;
    }
    
    void main() {
        int target = 8;
        int a[] = {2, 3, 5};
        std::vector<int> candidates(a, a + sizeof(a) / sizeof(int));
        
        std::vector<std::vector<int>> result = combinationSum(candidates, target);
        for (int i = 0; i < result.size(); i ++) {
            for (int j = 0; j < result[i].size(); j ++) {
                std::cout << result[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
};

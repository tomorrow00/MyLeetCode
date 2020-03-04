//
//  31_NextPermutation.cpp
//  LeetCode
//
//  Created by 王尚 on 2018/11/28.
//  Copyright © 2018 tomorrow. All rights reserved.
//

#include "header.h"

class NextPermutation {
public:
    void nextPermutation(std::vector<int>& nums) {
        if(nums.size()==1) return;
        
        auto res = nums.end();
        for(auto it = nums.end()-1;it!=nums.begin();--it){
            if(*(it-1)<*it) {
                res = it-1;
                break;
            }
        }
        if(res== nums.end()){
            std::reverse(nums.begin(), nums.end());
            return;
        }
        
        auto res2 = res+1;
        
        for(auto it = res2; it!=nums.end(); ++it)
            if(*it > *res && *it <= *res2) res2=it;
        
        iter_swap(res,res2);
        std::reverse(res+1, nums.end());
    }
    
    void main() {
        int a[] = {4, 5, 6};
        std::vector<int> nums(a, a + sizeof(a) / sizeof(int));
        
        nextPermutation(nums);
        
        for (int i = 0; i < sizeof(a) / sizeof(int); i ++) {
            std::cout << nums[i];
        }
        std::cout << std::endl;
    }
};

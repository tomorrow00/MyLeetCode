//
//  88_MergeSortedArray.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/3/7.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class MergeSortedArray {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, p = m + n - 1;
        
        while (p >= 0 && i >=0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[p] = nums1[i];
                i --;
            }
            else {
                nums1[p] = nums2[j];
                j --;
            }
            p --;
        }
        
        while (j >= 0) {
            nums1[p] = nums2[j];
            p --;
            j --;
        }
    }
    
    void main() {
        const int m = 3, n = 3;
        int a[m + n] = {7, 8, 9, 0, 0, 0};
        int b[n] = {2, 5, 6};
        std::vector<int> nums1(a, a + sizeof(a) / sizeof(int)), nums2(b, b + sizeof(b) / sizeof(int));
        
        merge(nums1, m, nums2, n);
        for (int i = 0; i < nums1.size(); i ++) {
            std::cout << nums1[i] << ' ';
        }
        std::cout << std::endl;
    }
};

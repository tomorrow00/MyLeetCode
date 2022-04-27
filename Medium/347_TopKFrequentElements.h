//
//  347_TopKFrequentElements.h
//  LeetCode
//
//  Created by 王尚 on 2020/2/19.
//  Copyright © 2020 tomorrow. All rights reserved.
//

#include "header.h"

class TopKFrequentElements {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> um;
        for (int num : nums) {
            um[num] ++;
        }

        std::vector<int> res;
        std::priority_queue<std::pair<int, int>> pq;
        for (auto item = um.begin(); item != um.end(); item ++) {
            pq.push(std::make_pair(item->second, item->first));
            if (pq.size() > um.size() - k) {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }

        return res;
    }
    
    void main() {
        int a[] = {1, 1, 1, 2, 2, 3};
        std::vector<int> nums(a, a + sizeof(a) / sizeof(int));
        int k = 2;
        
        std::vector<int> res = topKFrequent(nums, k);
        for (int i = 0; i < res.size(); i ++) {
            std::cout << res[i] << ' ';
        }
        std::cout << std::endl;
    }
};

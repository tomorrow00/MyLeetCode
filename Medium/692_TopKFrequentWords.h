//
//  692_TopKFrequentWords.h
//  LeetCode
//
//  Created by 王尚 on 2019/8/18.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class TopKFrequentWords {
public:
    std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k) {
        std::unordered_map<std::string, int> mp;
        for (auto &&word : words) {
            mp[word] ++;
        }
        
        std::vector<std::string> res(mp.size());
        size_t i = 0;
        for (auto it = mp.begin(); it != mp.end(); it ++) {
            res[i ++] = it->first;
        }
        
        std::sort(res.begin(), res.end(), [&](std::string a, std::string b) {
            if (mp[a] == mp[b]) return a < b;
            else return mp[a] > mp[b];
        });
        
        res.resize(k);
        
        return res;
    }
};

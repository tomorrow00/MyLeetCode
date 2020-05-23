//
//  933_NumberofRecentCalls.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/8/19.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

using namespace std;

class RecentCounter {
public:
    std::vector<int> q;
    RecentCounter() {
        q = std::vector<int>();
    }
    
    int ping(int t) {
        q.push_back(t);
        std::vector<int>::iterator lower;
        lower = lower_bound(q.begin(), q.end(), t - 3000);
        return static_cast<int>(q.size()- (lower - q.begin()));
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

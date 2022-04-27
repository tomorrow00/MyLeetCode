//
//  621_TaskScheduler.h
//  LeetCode
//
//  Created by 王尚 on 2019/8/18.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class TaskScheduler {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        std::unordered_map<char, int> ump;
        
        int count = 0;
        for (auto t : tasks) {
            ump[t] ++;
            count = std::max(ump[t], count);
        }
        
        int result = (count - 1) * (n + 1);
        for (auto u : ump) if (u.second == count) result ++;
        return std::max((int)tasks.size(), result);
    }
    
    void main() {
        char a[] = {'A', 'A', 'A', 'B', 'B', 'B'};
        std::vector<char> tasks(a, a + sizeof(a) / sizeof(char));
        int n = 2;
        
        std::cout << leastInterval(tasks, n) << std::endl;
    }
};

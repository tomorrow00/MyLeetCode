//
//  134_GasStation.h
//  LeetCode
//
//  Created by 王尚 on 2019/3/16.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class GasStation {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int total_tank = 0, curr_tank = 0, start_station = 0;
        
        for (int i = 0; i < gas.size(); i ++) {
            curr_tank += gas[i] - cost[i];
            total_tank += gas[i] - cost[i];
            if (curr_tank < 0) {
                start_station = i + 1;
                curr_tank = 0;
            }
        }
        
        return total_tank >= 0 ? start_station : -1;
    }
    
    void main() {
        int a[] = {1, 2, 3, 4, 4};
        std::vector<int> gas(a, a + sizeof(a) / sizeof(int));
        int b[] = {4, 4, 5, 1, 2};
        std::vector<int> cost(b, b + sizeof(b) / sizeof(int));
        
        std::cout << canCompleteCircuit(gas, cost) << std::endl;
    }
};

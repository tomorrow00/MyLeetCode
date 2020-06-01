//
//  57_InsertInterval.cpp
//  MyLeetCode
//
//  Created by 王尚 on 2020/5/23.
//  Copyright © 2020 tomorrow. All rights reserved.
//

#include "header.h"

using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class InsertInterval {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        
        return res;
    }
    
    void main() {
        Interval a[] = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
        vector<Interval> intervals(a, a + sizeof(a) / sizeof(Interval));
        Interval newInterval(4, 8);
        auto res = insert(intervals, newInterval);
        for (int i = 0; i < res.size(); i ++) {
            cerr << res[i].start << ' ' << res[i].end << endl;
        }
    }
};

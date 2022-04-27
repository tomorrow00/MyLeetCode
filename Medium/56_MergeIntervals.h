//
//  56_MergeIntervals.h
//  LeetCode
//
//  Created by 王尚 on 2019/2/21.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class MergeIntervals {
public:
    std::vector<Interval> merge(std::vector<Interval>& intervals) {
        if (intervals.empty()) return std::vector<Interval>{};
        
        std::sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        std::vector<Interval> res{intervals[0]};
        
        for (int i = 1; i < intervals.size(); i ++) {
            if (intervals[i].start > res.back().end) res.push_back(intervals[i]);
            else res.back().end = std::max(res.back().end, intervals[i].end);
        }
        
        return res;
    }
    
    void main() {
        int a[][2] = {
            {2, 3},
            {4, 5},
            {6, 7},
            {8, 9},
            {1, 10},
        };
        
        std::vector<Interval> intervals;
        for (int i = 0; i < sizeof(a) / sizeof(int) / 2; i ++) {
            Interval *temp = new Interval(a[i][0], a[i][1]);
            intervals.push_back(*temp);
            delete temp;
        }
        
        std::vector<Interval> res = merge(intervals);
        for (int i = 0; i < res.size(); i ++) {
            std::cout << res[i].start << ' ' << res[i].end << std::endl;
        }
    }
};

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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto pair = equal_range(intervals.begin(), intervals.end(), newInterval, [](const vector<int>& a, const vector<int>& b){return a[1] < b[0];});
        auto lower = pair.first;
        auto upper = pair.second;
        
        if (lower == upper) {
            intervals.insert(lower, newInterval);
        }
        else {
            upper --;
            upper->at(0) = min(newInterval[0], lower->at(0));
            upper->at(1) = max(newInterval[1], upper->at(1));
            intervals.erase(lower, upper);
        }
        
        return intervals;
    }
    
    void main() {
        vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
        vector<int> newInterval = {4, 8};
        auto res = insert(intervals, newInterval);
        for (int i = 0; i < res.size(); i ++) {
            cerr << res[i][0] << ' ' << res[i][1] << endl;
        }
    }
};

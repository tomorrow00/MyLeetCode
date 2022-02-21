//
//  84_LargestRectangleInHistogram.cpp
//  MyLeetCode
//
//  Created by 王尚 on 2021/8/31.
//  Copyright © 2021 tomorrow. All rights reserved.
//

#include "header.h"

class LargestRectangleInHistogram {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ret = 0;
        heights.push_back(0);
        vector<int> index;

        for (int i = 0; i < heights.size(); i++) {
            while (index.size() > 0 && heights[index.back()] >= heights[i]) {
                int h = heights[index.back()];
                index.pop_back();

                int sidx = index.size() > 0 ? index.back() : -1;
                if (h * (i - sidx - 1) > ret) {
                    ret = h * (i - sidx - 1);
                }
            }
            index.push_back(i);
        }
        
        return ret;
    }

    void main() {
        vector<int> heights = {2, 4};
        cerr << largestRectangleArea(heights) << endl;
    }
};
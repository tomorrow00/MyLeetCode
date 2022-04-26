//
//  149_MaxPoints.cpp
//  LeetCode
//  Max Points on a Line
//
//  Created by 王尚 on 2018/9/11.
//  Copyright © 2018年 tomorrow. All rights reserved.
//

#include "header.h"

class MaxPoints {
public:
    int maxPoints(std::vector<Point>& points) {
        
        return 0;
    }
    
    void main() {
        int a[][2] = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {4, 1}};
        std::vector<Point> points;
        
        for (int i = 0; i < sizeof(a) / sizeof(a[0]); i ++) {
            Point *p = new Point(a[i][0], a[i][1]);
            points.push_back(*p);
        }
        
        std::cout << maxPoints(points) << std::endl;
    }
};

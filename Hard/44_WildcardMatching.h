//
//  44_WildcardMatching.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/18.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

using namespace std;

class WildcardMatching {
public:
    bool isMatch(std::string s, std::string p) {
        // dp
//        int m = s.length(), n = p.length();
//        std::vector<std::vector<bool>> res(m + 1, std::vector<bool>(n + 1, false));
//        res[0][0] = true;
//        for (int i = 1; i <= n; i ++) {
//            if (p[i - 1] == '*') res[0][i] = res[0][i - 1];
//        }
//
//        for (int i = 1; i <= m; i ++) {
//            for (int j = 1; j <= n; j ++) {
//                if (p[j - 1] != '*') {
//                    res[i][j] = res[i - 1][j - 1] && (p[j - 1] == '?' || p[j - 1] == s[i - 1]);
//                }
//                else res[i][j] = res[i - 1][j] || res[i][j - 1];
//            }
//        }
//
//        return res[m][n];
        
        // greedy
        int m = static_cast<int>(s.length()), n = static_cast<int>(p.length());
        int si = 0, pi = 0;
        int sip = -1, pip = -1;
        while (si < m) {
            if (s[si] == p[pi] || p[pi] == '?') {
                pi ++;
                si ++;
            }
            else if (p[pi] == '*') {
                sip = si;
                pip = pi ++;
            }
            else {
                if (pip > -1) {
                    pi = pip + 1;
                    si = ++ sip;
                }
                else return false;
            }
        }
        
        while (p[pi] == '*') pi ++;
        
        return pi == n;
    }
    
    void main() {
        std::string s = "acbcb", p = "a*c?b";
        std::cout << isMatch(s, p) << std::endl;
    }
};

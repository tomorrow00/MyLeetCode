//
//  LongestSubstringWithoutRepeatingCharacters.cpp
//  LeetCode
//
//  Created by 王尚 on 2022/04/14.
//  Copyright © 2022 tomorrow. All rights reserved.
//

#include "header.h"

class LongestSubstringWithoutRepeatingCharacters {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> dict;
        int l = 0, len = 0;
        for (int r = 0; r < s.length(); ++r) {
            if (dict.find(s[r]) != dict.end()) {
                l = max(l, dict[s[r]] + 1);
            }
            dict[s[r]] = r;
            len = max(len, r - l + 1);
        }

        return len;
    }
    
    void main() {
        std::string s = "abba";
        cout << lengthOfLongestSubstring(s) << endl;
    }
};
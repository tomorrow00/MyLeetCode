//
//  451_SortCharactersByFrequency.h
//  LeetCode
//
//  Created by 王尚 on 2021/10/22.
//  Copyright © 2021 tomorrow. All rights reserved.
//

#include "header.h"

class SortCharactersByFrequency {
public:
    string frequencySort(string s) {
        std::unordered_map<char, int> freq;
        std::vector<string> bucket(s.size() + 1, "");
        string res;

        for (auto&& ch : s) {
            freq[ch] ++;
        }

        for (auto&& frq : freq) {
            char c = frq.first;
            int n = frq.second;
            bucket[n].append(n, c);
        }

        for (int i = s.size(); i > 0; i--) {
            if (!bucket[i].empty()) {
                res.append(bucket[i]);
            }
        }

        return res;
    }

    void main() {
        string s = "trere";
        cout << frequencySort(s) << endl;
    }
};
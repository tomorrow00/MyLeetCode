//
//  93_RestoreIPAddresses.h
//  LeetCode
//
//  Created by 王尚 on 2019/3/9.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

using namespace std;

class RestoreIPAddresses {
private:
    int max_length = 3;
    int max_count = 4;
    vector<string> vec;
    
    void helper(const string& s, const string& pre, int count) {
        count ++;
        
        if (count > max_count && s == "") {
            vec.push_back(pre);
            return;
        }
        
        if (count > max_count) return;
        
        string head_s, rest_s, res_s;
        int len = static_cast<int>(s.length());
        
        for (int i = 1; i <= max_length; i ++) {
            if (i > len) continue;
            
            head_s = s.substr(0, i);
            rest_s = s.substr(i, len - i);
            
            int tmp = stoi(head_s);
            if (tmp > 255 || tmp < 0 || head_s.length() != to_string(tmp).length()) continue;
            
            helper(rest_s, pre + "." + head_s, count);
        }
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        int len = static_cast<int>(s.length());
        if (len < 4) return vec;
        
        for (int i = 1; i <= max_length; i ++) {
            string head_s = s.substr(0, i);
            string rest_s = s.substr(i, len - i);
            
            int tmp = stoi(head_s);
            if (tmp > 255 || tmp < 0 || head_s.length() != to_string(tmp).length()) continue;
            
            helper(rest_s, to_string(tmp), 1);
        }
        
        return vec;
    }

    void main() {
        std::string s = "25525511135";
        
        std::vector<std::string> res = restoreIpAddresses(s);
        for (int i = 0; i < res.size(); i ++) {
            std::cout << res[i] << ' ';
        }
        std::cout << std::endl;
    }
};

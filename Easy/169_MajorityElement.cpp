
//
//  169_MajorityElement.cpp
//  LeetCode
//
//  Created by Tomorrow on 2022/2/21.
//  Copyright © 2022 tomorrow. All rights reserved.
//

class MajorityElement {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counters;
        for (auto num : nums) {
            if (++counters[num] > nums.size() / 2) {
                return num;
            }
        }
        return 0;
    }

    void main() {
        vector<int> nums = {6, 5, 5};
        cout << majorityElement(nums) << endl;
    }
};
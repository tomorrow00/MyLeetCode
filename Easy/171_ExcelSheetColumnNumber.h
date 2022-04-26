
//
//  171_ExcelSheetColumnNumber.cpp
//  LeetCode
//
//  Created by Tomorrow on 2022/2/22.
//  Copyright © 2022 tomorrow. All rights reserved.
//

class ExcelSheetColumnNumber {
public:
    int titleToNumber(string columnTitle) {
        int number = 0;
        // for (int i = columnTitle.size() - 1; i >= 0; i--) {
        //     number += (columnTitle[i] - 'A' + 1) * std::pow(26, (columnTitle.size() - i - 1));
        // }
        for (auto c : columnTitle) {
            int d = c - 'A' + 1;
            number = number * 26 + d;
        }

        return number;
    }

    void main() {
        std::string columnTitle = "AA";
        cout << titleToNumber(columnTitle) << endl;
    }
};
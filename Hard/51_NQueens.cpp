//
//  51_NQueens.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/20.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

using namespace std;

class NQueens {
private:
    void solveNQueens(int row, const int& n, vector<vector<string>>& res, vector<string>& ans, vector<int>& flag_col, vector<int>& flag_45, vector<int>& flag_135) {
        if (row == n) {
            res.push_back(ans);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (flag_col[col] && flag_45[row + col] && flag_135[n - 1 + col - row]) {
                flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 0;
                ans[row][col] = 'Q';
                solveNQueens(row + 1, n, res, ans, flag_col, flag_45, flag_135);
                flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 1;
                ans[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> ans(n, string(n, '.'));
        vector<int> flag_col(n, 1), flag_45(2 * n - 1, 1), flag_135(2 * n - 1, 1);
        solveNQueens(0, n, res, ans, flag_col, flag_45, flag_135);
        
        return res;
    }
    
    void main() {
        int n = 4;
        vector<vector<string>> res = solveNQueens(n);
        for (int i = 0; i < res.size(); i ++) {
            for (int j = 0; j < res[i].size(); j ++) {
                cout << res[i][j] << endl;
            }
            cout << endl;
        }
    }
};

//
//  95_UniqueBinarySearchTreesII.cpp
//  LeetCode
//
//  Created by Tomorrow on 2020/3/6.
//  Copyright © 2020 tomorrow. All rights reserved.
//

#include "header.h"
#include "init.h"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class UniqueBinarySearchTreesII {
private:
    vector<TreeNode*> helper(int from, int to) {
        vector<TreeNode*> ret;

        if (to - from < 0) ret.push_back(nullptr);
        else if (to - from == 0) ret.push_back(new TreeNode(from));
        else {
            for(int i = from; i <= to; i++) {
                auto lt = helper(from, i - 1);
                auto rt = helper(i + 1, to);

                for (int j = 0; j < lt.size(); ++j) {
                    for (int k = 0; k < rt.size(); ++k) {
                        auto m = new TreeNode(i);
                        m->left = lt[j];
                        m->right = rt[k];
                        ret.push_back(m);
                    }
                }
            }
        }

        return ret;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return helper(1, n);
    }

    void main() {
        int n = 0;
        auto ret = generateTrees(n);
        for (int i = 0; i < ret.size(); ++i) {
            cout << ret[i]->val << endl;
        }
    }
};
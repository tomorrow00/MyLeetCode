//
//  653_TwoSumIV.cpp
//  LeetCode
//
//  Created by 王尚 on 2021/8/23.
//  Copyright © 2021 tomorrow. All rights reserved.
//

#include <unordered_set>

#include "header.h"
#include "init.h"

class TwoSumIV {
private:
    std::unordered_set<int> us;

public:
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) {
            return false;
        }
        if (us.count(k - root->val)) {
            return true;
        }
        us.insert(root->val);

        return findTarget(root->left, k) || findTarget(root->right, k);
    }

    void main() {
        TreeNode* root;
        char a[] = {'5', '3', '6', '2', '4', '#', '7'};
        Initialization init;
        init.InitTree(root, a, 0, sizeof(a) / sizeof(char));

        int k = 9;

        std::cerr << findTarget(root, k) << std::endl;
    }
};
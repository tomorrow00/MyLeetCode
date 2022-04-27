//
//  129_SumRoottoLeafNumbers.h
//  LeetCode
//
//  Created by Tomorrow on 2021/11/3.
//  Copyright © 2021 tomorrow. All rights reserved.
//

#include "header.h"
#include "init.h"

class SumRoottoLeafNumbers {
private:
    int sumNumbers(TreeNode* root, int sum) {
        return root->left == root->right ? sum * 10 + root->val :
                ((root->left ? sumNumbers(root->left, sum * 10 + root->val) : 0) + 
                (root->right ? sumNumbers(root->right, sum * 10 + root->val) : 0));
    }
public:
    int sumNumbers(TreeNode* root) {
        return sumNumbers(root, 0);
    }

    void main() {
        TreeNode* root;
        char a[] = {'4', '9', '0', '5', '1'};
        Initialization init;
        init.InitTree(root, a, 0, sizeof(a) / sizeof(char));

        cerr << sumNumbers(root) << endl;
    }
};
//
//  98_ValidateBinarySearchTree.h
//  LeetCode
//
//  Created by Tomorrow on 2020/5/22.
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class ValidateBinarySearchTree {
private:
    bool isValidBST(TreeNode* root, long min, long max) {
        if (!root) return true;
        if (root->val <= min || root->val >= max) return false;
        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

    void main() {
        TreeNode* root;
        char a[] = {'1', '#', '2', '3'};
        Initialization init;
        init.InitTree(root, a, 0, sizeof(a) / sizeof(char));
        cerr << isValidBST(root) << endl;
    }
};

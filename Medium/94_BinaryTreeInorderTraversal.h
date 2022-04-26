//
//  94_BinaryTreeInorderTraversal.cpp
//  LeetCode
//
//  Created by Tomorrow on 2020/2/7.
//  Copyright © 2020 tomorrow. All rights reserved.
//

#include "header.h"
#include "init.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BinaryTreeInorderTraversal {
private:
    void inorder(TreeNode* root, std::vector<int>& res) {
        if (root == nullptr) return;

        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        inorder(root, res);
        
        return res;
    }
    
    void main() {
        TreeNode* root;
        char a[] = {'1', '#', '2', '3'};
        Initialization init;
        init.InitTree(root, a, 0, sizeof(a) / sizeof(char));

       std::cout << root->val << std::endl;
    }
};

//
//  100_SameTree.cpp
//  MyLeetCode
//
//  Created by 王尚 on 2020/5/23.
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
class SameTree {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) return (p == q);
        else return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
    
    void main() {
        TreeNode *p, *q;
        char a[] = {'1', '#', '2', '3'};
        char b[] = {'1', '#', '2', '3'};
        Initialization init;
        init.InitTree(p, a, 0, sizeof(a) / sizeof(char));
        init.InitTree(q, b, 0, sizeof(b) / sizeof(char));
        
        cerr << isSameTree(p, q) << endl;
    }
};

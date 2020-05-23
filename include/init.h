//
//  init.h
//  LeetCode
//  初始化
//
//  Created by 王尚 on 2018/11/20.
//  Copyright © 2018 tomorrow. All rights reserved.
//

#ifndef INIT_H
#define INIT_H

#include "header.h"

class Initialization {
public:
    void initList(ListNode *&pHead, int a[], int length) {
        ListNode *p = nullptr, *s;
        
        for (int i = 0; i < length; i ++) {
            s = new ListNode(a[i]);
            if (i == 0) {
                pHead = s;
                p = pHead;
            }
            p->next = s;
            p = p->next;
        }
    }
    
    void InitTree(TreeNode *&pRoot, char* a, int index, int len) {
        if (index >= len) {
            return;
        }
        
        if (a[index] != '#') {
            pRoot = new TreeNode(static_cast<int>(a[index] - 48));
        }
        else {
            return;
        }
        
        pRoot->left = NULL;
        pRoot->right = NULL;
        InitTree(pRoot->left, a, 2 * index + 1, len);
        InitTree(pRoot->right, a, 2 * index + 2, len);
    }
    
    void InitRandomList(RandomListNode *&pHead, int a[], int length) {
        RandomListNode *p = nullptr, *s;
        for (int i = 0; i < length; i ++) {
            s = new RandomListNode(a[i]);
            if (i == 0) {
                p = s;
                pHead = p;
                continue;
            }
            p->next = s;
            p = p->next;
        }
    }
};

#endif /* INIT_H */

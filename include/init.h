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
    void InitList(ListNode *&pHead, int a[], int length) {
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

    void InitCycleList(ListNode *&pHead, int a[], int length, int pos) {
        ListNode *p = nullptr, *s;
        ListNode *pos_p = nullptr, *tail;
        
        for (int i = 0; i < length; i ++) {
            s = new ListNode(a[i]);
            if (i == 0) {
                pHead = s;
                p = pHead;
            }
            p->next = s;
            p = p->next;

            if (i == pos) {
                pos_p = s;
            }
            if (i == length - 1) {
                tail = s;
            }
        }

        tail->next = pos_p;
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

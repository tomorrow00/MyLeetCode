//
//  61_RotateList.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/2/25.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"
#include "init.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class RotateList {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length ++;
        }
        
        k %= length;
        if (k == 0) return head;
        ListNode* p = head, *new_head;
        for (int i = 1; i < length - k; i ++) {
            p = p->next;
        }
        new_head = p->next;
        p->next = NULL;
        tail->next = head;
        
        return new_head;
    }
    
    void main() {
        ListNode* head;
        int a[] = {0, 1, 2};
        Initialization init;
        init.InitList(head, a, 3);
        
        int k = 3;
        ListNode* res = rotateRight(head, k);
        ListNode* p = res;
        while (p) {
            std::cout << p->val << ' ';
            p = p->next;
        }
        std::cout << std::endl;
    }
};

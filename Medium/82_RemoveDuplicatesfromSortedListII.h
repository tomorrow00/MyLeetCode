//
//  82_RemoveDuplicatesfromSortedListII.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/3/4.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class RemoveDuplicatesfromSortedListII {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *p;
        p = head;
        
        while (p != NULL && p->val == head->val) {
            p = p->next;
        }
        
        if (head->next == p) {
            if (p == NULL) {
                return head;
            }
            head->next = deleteDuplicates(p);
        }
        else {
            head = deleteDuplicates(p);
        }
        
        
        return head;
    }
};

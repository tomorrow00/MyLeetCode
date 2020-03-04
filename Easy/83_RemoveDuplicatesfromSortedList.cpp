
//
//  83_RemoveDuplicatesfromSortedList.cpp
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

class RemoveDuplicatesfromSortedList {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode *p, *r;
        p = head;
        r = p->next;
        
        while (r->next != NULL) {
            if (r->val == p->val) {
                r = r->next;
                p->next = r;
            }
            else {
                p = p->next;
                r = r->next;
            }
        }
        
        if (r->val == p->val) {
            p->next = r->next;
        }
        
        return head;
    }
};

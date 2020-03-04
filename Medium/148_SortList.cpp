//
//  148_SortList.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/8/25.
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
class SortList {
public:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        if (!head1) return head2;
        if (!head2) return head1;
        
        ListNode* newhead = new ListNode(0);
        ListNode* p = newhead;
        
        while (head1 || head2) {
            if (head1 && (!head2 || (head1->val <= head2->val))) {
                p->next = head1;
                p = p->next;
                head1 = head1->next;
            }
            if (head2 && (!head1 || (head2->val < head1->val))) {
                p->next = head2;
                p = p->next;
                head2 = head2->next;
            }
        }
        
        return newhead->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *headb = slow->next;
        slow->next = NULL;
        
        return merge(sortList(head), sortList(headb));
    }
    
    void main() {
        int a[] = {-1, 5, 3, 4, 0};
        Initialization init;
        ListNode *pH;
        init.initList(pH, a, sizeof(a) / sizeof(int));
        
        ListNode* res = sortList(pH);
        while (res) {
            std::cout << res->val << ' ';
            res = res->next;
        }
        std::cout << std::endl;
    }
};

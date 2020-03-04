//
//  86_PartitionList.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/3/6.
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

class PartitionList {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *p1 = new ListNode(0);
        ListNode *p2 = new ListNode(0);
        ListNode *pHead1 = p1, *pHead2 = p2;
        
        while (head) {
            if (head->val < x) {
                p1->next = head;
                p1 = p1->next;
            }
            else {
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }

        p2->next = NULL;
        p1->next = pHead2->next;

        return pHead1->next;
    }
    
    void main() {
        const int n = 6;
        int a[n] = {1, 4, 3, 2, 5, 2};
        ListNode* head;
        int x = 3;
        
        Initialization init;
        init.initList(head, a, n);
        
        head = partition(head, x);
        while (head->next) {
            std::cout << head->val << ' ';
            head = head->next;
        }
        std::cout << std::endl;
    }
};

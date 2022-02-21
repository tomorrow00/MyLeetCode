//
//  92_ReverseLinkedListII.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/3/8.
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

class ReverseLinkedListII {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *pre = nullptr, *p = head, *tempHead = nullptr;
        for (int i = 0; i < m - 1; i ++) {
            pre = p;
            p = p->next;
        }
        
        tempHead = p;
        for (int i = 0; i < n - m; i ++) {
            ListNode* temp = p->next;
            p->next = p->next->next;
            temp->next = tempHead;
            tempHead = temp;
        }
        
        if (pre == nullptr) {
            head = tempHead;
        }
        else {
            pre->next = tempHead;
        }
        
        return head;
    }
    
    void main() {
        ListNode* head;
        int length = 5;
        int a[] = {1, 2, 3, 4, 5};
        Initialization init;
        init.InitList(head, a, length);
        int m = 1, n = 5;
        
        head = reverseBetween(head, m, n);
        while (head) {
            std::cout << head->val << ' ';
            head = head->next;
        }
        std::cout << std::endl;
    }
};

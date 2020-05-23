//
//  25_ReverseNodesink-Group.cpp
//  LeetCode
//
//  Created by 王尚 on 2018/11/22.
//  Copyright © 2018 tomorrow. All rights reserved.
//

#include "header.h"
#include "init.h"

class ReverseNodesinkGroup {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        
        ListNode *pre = new ListNode(-1);
        ListNode *cur, *next, *newhead;
        pre->next = head;
        newhead = pre;
        cur = pre;
        
        int length = 0;
        while (cur == cur->next) length ++;
        
        while (length >= k) {
            cur = pre->next;
            next = cur->next;
            for (int i = 1; i < k; i ++) {
                cur->next = next->next;
                next->next = pre->next;
                pre->next = next;
                next = cur->next;
            }
            pre = cur;
            length -= k;
        }
        
        return newhead->next;
    }
    
    void main() {
        int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int k = 3;
        
        Initialization init;
        ListNode *head;
        init.initList(head, a, sizeof(a) / sizeof(int));
        
        ListNode *res = reverseKGroup(head, k);
        while (res) {
            std::cout << res->val;
            res = res->next;
        }
        std::cout << std::endl;
    }
};

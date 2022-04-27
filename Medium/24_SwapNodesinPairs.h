//
//  24_SwapNodesinPairs.h
//  LeetCode
//
//  Created by 王尚 on 2018/11/22.
//  Copyright © 2018 tomorrow. All rights reserved.
//

#include "header.h"
#include "init.h"

class SwapNodesinPairs {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *next = head->next;
        head->next = next->next;
        next->next = head;
        head->next = swapPairs(head->next);
        
        return next;
    }
    
    void main() {
        int a[] = {1, 2, 3, 4, 5};
        
        Initialization init;
        ListNode *head;
        init.InitList(head, a, sizeof(a) / sizeof(int));
        
        ListNode *res = swapPairs(head);
        while (res) {
            std::cout << res->val;
            res = res->next;
        }
        std::cout << std::endl;
    }
};

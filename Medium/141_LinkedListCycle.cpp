//
//  141_LinkedListCycle.cpp
//  LeetCode
//
//  Created by 王尚 on 2022/1/19.
//  Copyright © 2022 tomorrow. All rights reserved.
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
class LinkedListCycle {
public:
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }

        ListNode *slow = head, *fast = head;
        
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                return true;
            }
        }
        
        return false;
    }

    void main() {
        int a[] = {6, 3, 2, 1, 8, 4, 5, 6, 0, -4};
        int pos = 0;
        
        Initialization init;
        ListNode *head;
        init.InitCycleList(head, a, sizeof(a) / sizeof(int), pos);

        cout << hasCycle(head) << endl;
    }
};
//
//  142_LinkedListCycleII.h
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
class LinkedListCycleII {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) {
            return nullptr;
        }

        ListNode *slow = head, *fast = head;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                fast = head;
                while (fast != slow) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return nullptr;
    }

    void main() {
        int a[] = {3, 2, 0, -4};
        int pos = 1;
        
        Initialization init;
        ListNode *head;
        init.InitCycleList(head, a, sizeof(a) / sizeof(int), pos);

        cout << detectCycle(head)->val << endl;
    }
};
//
//  23_MergekSortedLists.cpp
//  LeetCode
//
//  Created by 王尚 on 2018/11/20.
//  Copyright © 2018 tomorrow. All rights reserved.
//

#include "header.h"
#include "init.h"

class MergeKLists {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        while (lists.size() > 1) {
            lists.push_back(merge2Lists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        
        return lists.front();
    }
    
    ListNode* merge2Lists(ListNode *l1, ListNode*l2) {
        if (!l1) return l2;
        if (!l2) return l1;
    
        if (l1->val < l2->val) {
            l1->next = merge2Lists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = merge2Lists(l1, l2->next);
            return l2;
        }
    }
    
    void main() {
        std::vector<ListNode *> lists;
        int n = 3;
        int a[] = {1, 4, 5};
        int b[] = {1, 3, 4};
        int c[] = {2, 6};
        
        Initialization init;
        ListNode *pH1, *pH2, *pH3;
        init.initList(pH1, a, sizeof(a) / sizeof(int));
        init.initList(pH2, b, sizeof(b) / sizeof(int));
        init.initList(pH3, b, sizeof(b) / sizeof(int));
        lists.push_back(pH1);
        lists.push_back(pH2);
        lists.push_back(pH3);
        
        ListNode *res = mergeKLists(lists);
        while (res) {
            std::cout << res->val << std::endl;
            res = res->next;
        }
    }
};

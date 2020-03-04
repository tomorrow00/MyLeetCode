//
//  622_DesignCircularQueue.cpp
//  LeetCode
//
//  Created by 王尚 on 2019/8/19.
//  Copyright © 2019 tomorrow. All rights reserved.
//

#include "header.h"

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        q.resize(k);
        head = 0;
        rear = 0;
        empty = true;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;
        q[rear] = value;
        rear ++;
        rear %= q.size();
        empty = false;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;
        head ++;
        head %= q.size();
        if (head == rear) empty = true;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) return -1;
        return q[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) return -1;
        if (rear == 0) return q.back();
        else return q[rear - 1];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if (head == rear && empty) return true;
        return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if (head == rear && !empty) return true;
        return false;
    }
    
private:
    std::vector<int> q;
    int head;
    int rear;
    bool empty;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

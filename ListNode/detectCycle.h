//
// Created by Lee on 2022/10/15.
//
// 快慢指针法， 只要fast的指针一直移动的比slow的两倍，就一定会相遇
// 看一下推导的公式 书籍里面
#ifndef DATASTRUCTURE_DETECTCYCLE_H
#define DATASTRUCTURE_DETECTCYCLE_H
#include "iostream"
#include "ListNode.h"

using namespace std;

ListNode* detectCycle(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        //快慢指针相遇
        if(slow == fast){
            ListNode* index1 = head;
            ListNode* index2 = slow;
            while(index1 != index2){
                index2 = index2->next;
                index1 = index1->next;
            }
            return index1;
        }
    }
    return nullptr;
}

#endif //DATASTRUCTURE_DETECTCYCLE_H

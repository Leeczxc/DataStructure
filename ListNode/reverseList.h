//
// Created by Lee on 2022/10/15.
//

#ifndef DATASTRUCTURE_REVERSELIST_H
#define DATASTRUCTURE_REVERSELIST_H
#include "iostream"
#include "ListNode.h"

using namespace std;

// 双指针法
void reverseListNode(ListNode* head){
    if(head == nullptr)
        return;
    ListNode* Head = head;
    ListNode* temp = head->next;
    Head->next = nullptr;
    while (temp != nullptr){
        auto t = temp;
        temp = temp->next;
        t->next = Head->next;
        head->next = t;
    }
}
#endif //DATASTRUCTURE_REVERSELIST_H

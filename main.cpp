//
// Created by Lee on 2022/10/14.
//
#include "iostream"
#include "ListNode.h"
#include "reverseList.h"
#include "removeNthFromEnd.h"

using namespace std;

ListNode* getNLenghtList(int n){
    ListNode* head = new ListNode(0);
    auto temp = head;
    for(int i = 1; i <= n; i++){
        auto t= new ListNode(i);
        temp->next = t;
        temp = temp->next;
    }
    return head;
}

int main(){
    auto head = getNLenghtList(9);
    // 反转
//    reverseListNode(head);
    removeNFromEnd(head,5);
    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
}

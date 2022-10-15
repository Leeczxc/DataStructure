//
// Created by Lee on 2022/10/15.
//

#ifndef DATASTRUCTURE_REMOVENTHFROMEND_H
#define DATASTRUCTURE_REMOVENTHFROMEND_H
// 删除从后面属第N个节点
#include "iostream"
#include "ListNode.h"

using namespace std;

void removeNFromEnd(ListNode* head, int length){
   auto nNode = head;
   int pos = 0;
   // 这里要注意一下开头有一个head
   while(nNode != nullptr && pos < length - 1){
       nNode = nNode->next;
       pos++;
   }
   if(nNode == nullptr)
       return;
   if(nNode->next == nullptr){
       auto t = head;
       head = head->next;
       delete t;
   }
   auto pre = head;
   auto node = head->next;
   nNode = nNode->next;
   while(nNode->next != nullptr){
       pre = node;
       node = node->next;
       nNode = nNode->next;
   }
   pre->next = node->next;
   delete node;
}
#endif //DATASTRUCTURE_REMOVENTHFROMEND_H

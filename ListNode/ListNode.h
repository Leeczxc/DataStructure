//
// Created by Lee on 2022/10/14.
//

#ifndef DATASTRUCTURE_LISTNODE_H
#define DATASTRUCTURE_LISTNODE_H
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr){};
};
#endif //DATASTRUCTURE_LISTNODE_H

//
// Created by Lee on 2022/10/14.
//
#include "iostream"
#include "evalRPN.h"
#include "maxSliding239.h"

using namespace std;

//ListNode* getNLenghtList(int n){
//    ListNode* head = new ListNode(0);
//    auto temp = head;
//    for(int i = 1; i <= n; i++){
//        auto t= new ListNode(i);
//        temp->next = t;
//        temp = temp->next;
//    }
//    return head;
//}

int main(){
//    auto head = getNLenghtList(9);
//    // 反转
////    reverseListNode(head);
//    removeNFromEnd(head,5);
//    while(head != nullptr){
//        cout << head->val << " ";
//        head = head->next;
//    }
//    MyStack t;
//    t.push(1);
//    t.push(2);
//    cout << t.pop();
//    cout << t.top();
//    vector<string> tokens{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
//    cout << evalRPN(tokens);
    vector<int> nums{1, -1};
    for(auto num : maxSlidingWindow(nums,1)){
        cout << num << " ";
    }
}

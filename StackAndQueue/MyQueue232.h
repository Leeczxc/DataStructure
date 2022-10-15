//
// Created by Lee on 2022/10/15.
//
// 用两个队列实现栈功能
#ifndef DATASTRUCTURE_MYQUEUE232_H
#define DATASTRUCTURE_MYQUEUE232_H
#include "iostream"
#include "deque"
#include "stack"
using namespace std;


//class MyQueue {
//public:
//    stack<int>* deque1;
//    stack<int>* deque2;
//
//    MyQueue() {
//        deque1 = new stack<int>;
//        deque2 = new stack<int>;
//    }
//
//    void push(int x) {
//        deque1->emplace(x);
//    }
//
//    int pop() {
//        auto t = peek();
//        deque2->pop();
//        return t;
//    }
//
//    int peek() {
//        if(deque2->empty()){
//            while(!deque1->empty()){
//                auto t = deque1->front();
//                deque2->emplace_back(t);
//                deque1->pop_front();
//            }
//        }
//        auto t = deque2->front();
//        return t;
//    }
//
//    bool empty() {
//        if(deque1->empty() && deque2->empty())
//            return true;
//        return false;
//    }
//};
#endif //DATASTRUCTURE_MYQUEUE232_H

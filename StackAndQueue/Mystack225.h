//
// Created by Lee on 2022/10/15.
//
// 用两个队列实现栈

#ifndef DATASTRUCTURE_MYSTACK225_H
#define DATASTRUCTURE_MYSTACK225_H
#include "iostream"
#include "queue"

using namespace std;

class MyStack {
public:
    queue<int>* queue1;
    queue<int>* queue2;
    MyStack() {
        queue1 = new queue<int>;
        queue2 = new queue<int>;
    }

    void push(int x) {
        queue1->emplace(x);
    }

    int pop() {
        int x = top();
        queue1->pop();
        return x;
    }

    int top() {
        if(queue1->size() == 0)
            swap(queue1, queue2);
        size_t size = queue1->size();
        for(int i = 0; i < size - 1; i++){
            int x = queue1->front();
            queue2->emplace(x);
            queue1->pop();
        }
        int x = queue1->front();
        return x;
    }

    bool empty() {
        if(queue1->empty() && queue2->empty())
            return true;
        return false;
    }
};


#endif //DATASTRUCTURE_MYSTACK225_H

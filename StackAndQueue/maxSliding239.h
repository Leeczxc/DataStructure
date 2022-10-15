//
// Created by Lee on 2022/10/15.
//
// 建立数据结构，然后维护
#ifndef DATASTRUCTURE_MAXSLIDING239_H
#define DATASTRUCTURE_MAXSLIDING239_H
#include "iostream"
#include "vector"
#include "deque"

using namespace std;

class MyQue{
public:
    deque<int> que;
    void pop(int value){
        if(!que.empty() && value == que.front()){
            que.pop_back();
        }
    }

    void push(int value){
        while(!que.empty() && value > que.back()){
            que.pop_back();
        }
        que.push_back(value);
    }

    int pop_front(){
        return que.front();
    }
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    size_t size = nums.size();
    if(size < k)
        return vector<int>();
    MyQue que;
    for(int i = 0 ; i < k; i++){
        que.push(nums[i]);
    }
    vector<int> ans;
    for(int i = k; i< size; i++){
        ans.emplace_back(que.pop_front());
        que.pop(nums[i-k]);
        que.push(nums[i]);
    }
    ans.emplace_back(que.pop_front());
    return ans;
}
#endif //DATASTRUCTURE_MAXSLIDING239_H

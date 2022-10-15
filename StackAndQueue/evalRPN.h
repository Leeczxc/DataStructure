//
// Created by Lee on 2022/10/15.
//
// 逆波兰表达式

#ifndef DATASTRUCTURE_EVALRPN_H
#define DATASTRUCTURE_EVALRPN_H
#include "iostream"
#include "stack"
#include "vector"

using namespace std;

int evalRPN(vector<string> tokens) {
    stack<string> str;
    for(auto s : tokens){
        if(s == "+"){
            double second = stod(str.top());
            str.pop();
            double first = stod(str.top());
            str.pop();
            double ans = first + second;
            str.emplace(to_string(ans));
        }else if(s == "-"){
            double second = stod(str.top());
            str.pop();
            double first = stod(str.top());
            str.pop();
            double ans = first - second;
            str.emplace(to_string(ans));
        }else if(s == "*"){
            double second = stod(str.top());
            str.pop();
            double first = stod(str.top());
            str.pop();
            double ans = first * second;
            str.emplace(to_string(ans));
        }else if(s == "/"){
            double second = stod(str.top());
            str.pop();
            double first = stod(str.top());
            str.pop();
            int ans = first / second;
            str.emplace(to_string(ans));
        }else{
            str.emplace(s);
        }
    }
    return stoi(str.top());
}
#endif //DATASTRUCTURE_EVALRPN_H

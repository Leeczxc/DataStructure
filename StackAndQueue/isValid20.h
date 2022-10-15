//
// Created by Lee on 2022/10/15.
//
// 括号匹配
// 题解的反向也挺好的
#ifndef DATASTRUCTURE_ISVALID20_H
#define DATASTRUCTURE_ISVALID20_H
#include "iostream"
#include "stack"

using namespace std;

bool isValid(string s) {
    stack<char> str;
    for(auto c : s){
        switch(c){
            case '(':
            case '{':
            case '[': str.emplace(c);break;
            case ')':
                if(str.size() == 0)
                    return false;
                if(str.top() == '(')
                    str.pop();
                else
                    return false;
                break;
            case '}':
                if(str.size() == 0)
                    return false;
                if(str.top() == '{')
                    str.pop();
                else
                    return false;
                break;
            case ']':
                if(str.size() == 0)
                    return false;
                if(str.top() == '[')
                    str.pop();
                else
                    return false;
                break;
        }
    }
    if(str.size() == 0)
        return true;
    return false;
}

#endif //DATASTRUCTURE_ISVALID20_H

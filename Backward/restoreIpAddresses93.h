//
// Created by Lee on 2022/10/31.
//

#ifndef DATASTRUCTURE_RESTOREIPADDRESSES93_H
#define DATASTRUCTURE_RESTOREIPADDRESSES93_H
#include "iostream"
#include "vector"

using namespace std;

vector<string> result;

bool isvalid(string& s, int start, int end){
    if(start > end)
        return false;
    if(s[start] == '0' && start != end){
        return false;
    }
    int num = 0;
    for(int i = start; i <= end; i++){
        if(s[i] > '9' || s[i] < '0')
            return false;
        num = num * 10 + (s[i] - '0');
        if(num > 255)
            return false;
    }
    return true;
}

void backtracking(string& s, int startindex, int pointnum){
    if(pointnum == 3){
        if(isvalid(s, startindex, s.size() - 1))
            result.emplace_back(s);
        return;
    }
    for(int i = startindex; i < s.size(); i++){
        if(isvalid(s, startindex, i)){
            s.insert(s.begin() + i + 1, '.');
            pointnum++;
            backtracking(s, i + 2, pointnum);
            pointnum--;
            s.erase(s.begin() + i + 1);
        }
        else
            break;
    }
}

vector<string> restoreIprAdresses(string s) {
    result.clear();
    if(s.size() > 12)
        return result;
    backtracking(s, 0, 0);
    return result;
}
#endif //datastructure_restoreipaddresses93_h

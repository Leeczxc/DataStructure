//
// Created by Lee on 2022/10/31.
//

#ifndef DATASTRUCTURE_PARTITION131_H
#define DATASTRUCTURE_PARTITION131_H
#include "iostream"
#include "vector"

using namespace std;

vector<vector<string>> result;
vector<string> path;

// 判断回文
bool isRight(string& subs){
    if(subs.size() == 1)
        return true;
    int pos = 0;
    while(pos <= subs.size() - 1 -pos){
        if(subs[pos] != subs[subs.size() - 1 -pos])
            return false;
        pos++;
    }
    return true;
}

void backtracking(string& s, int start){
    if(start >= s.size()){
        result.emplace_back(path);
        return;
    }
    for(int i  = start; i < s.size(); i++){
        string str = s.substr(start, i - start + 1);
        if(isRight(str)){
            path.emplace_back(str);
        }else
            continue;
        backtracking(s, i + 1);
        path.pop_back();
    }
}

vector<vector<string>> partition(string s) {
    result.clear();
    path.clear();
    backtracking(s, 0);
    return result;
}
#endif //DATASTRUCTURE_PARTITION131_H

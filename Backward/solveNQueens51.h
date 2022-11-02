//
// Created by Lee on 2022/11/1.
//

#ifndef DATASTRUCTURE_SOLVENQUEENS51_H
#define DATASTRUCTURE_SOLVENQUEENS51_H

#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

vector<vector<string>> result;
vector<string> path;
unordered_map<int, int> pos;

// 这个还是判断上出了问题
// 原文要求的是对斜线和每一列进行判断
// 45和135都要进行判断
bool isValid(unordered_map<int, int>& pos){
    if(pos.size() <= 1)
        return true;
    auto ite1 = pos.begin();
    ite1++;
    auto ite2 = pos.begin();
    while(ite1 != pos.end()){
        if(abs(ite1->first - ite2->first) == 1)
            return false;
        ite1++;
        ite2++;
    }
    for(int i = 0; i < )
    return true;
}

void backtracking(int n, vector<bool>& used){
    if(path.size() == n){
        result.emplace_back(path);
        return;
    }
    for(int i = 0; i < n; i++){
        if(!used[i]){
            if(pos.find(i) == pos.end()){
                pos[i]++;
                if(isValid(pos)){
                    string str(n, '.');
                    str[i] = 'Q';
                    path.emplace_back(str);
                    used[i] = true;
                    backtracking(n, used);
                    used[i] = false;
                    path.pop_back();
                }
                pos.erase(i);
            }
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    result.clear();
    path.clear();
    vector<bool> used(n, false);
    backtracking(n, used);
    return result;
}
#endif //DATASTRUCTURE_SOLVENQUEENS51_H

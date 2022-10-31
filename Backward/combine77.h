//
// Created by Lee on 2022/10/30.
//

#ifndef DATASTRUCTURE_COMBINE77_H
#define DATASTRUCTURE_COMBINE77_H
#include "iostream"
#include "vector"

using namespace std;

vector<vector<int>> result;
vector<int> path;
void backtracking(int n, int k, int startIndex){
    if(path.size() == k){
        result.emplace_back(path);
        return;
    }
    for(int i = startIndex; i <= n ; i++){
        path.emplace_back(i);
        backtracking(n, k , i + 1);
        path.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    result.clear();
    path.clear();
    backtracking(n, k, 1);
    return result;
}
#endif //DATASTRUCTURE_COMBINE77_H

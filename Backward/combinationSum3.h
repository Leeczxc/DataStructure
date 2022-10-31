//
// Created by Lee on 2022/10/31.
//

#ifndef DATASTRUCTURE_COMBINATIONSUM3_H
#define DATASTRUCTURE_COMBINATIONSUM3_H
#include "iostream"
#include "vector"

using namespace std;

vector<vector<int>> result;
vector<int> path;

void backtracking(int k, int n, int startIndex, int sum){
    if(sum > n)
        return;
    if(sum == n  && path.size() == k){
        result.emplace_back(path);
        return;
    }
    for(int i = startIndex; i <= 9 && path.size() < n; i++){
        path.emplace_back(i);
        backtracking(k, n, i + 1, sum + i);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    result.clear();
    path.clear();
    backtracking(k, n, 1, 0);
    return result;
}
#endif //DATASTRUCTURE_COMBINATIONSUM3_H

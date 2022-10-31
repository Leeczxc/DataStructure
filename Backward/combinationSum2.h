//
// Created by Lee on 2022/10/31.
//

#ifndef DATASTRUCTURE_COMBINATIONSUM2_H
#define DATASTRUCTURE_COMBINATIONSUM2_H
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

vector<vector<int>> result;
vector<int> path;

void backtracking(vector<int>& candidates, int& target, int sum, int startIndex, vector<bool>& used){
    if(sum > target)
        return;
    if(sum == target){
        result.emplace_back(path);
        return;
    }
    if(startIndex == candidates.size())
        return;
    for(int i = startIndex; i < candidates.size(); i++){
        if(i > 0 && candidates[i] == candidates[i - 1] && !used[i - 1])
            continue;
        used[i] = true;
        path.emplace_back(candidates[i]);
        backtracking(candidates, target, sum + candidates[i], i + 1, used);
        used[i] = false;
        path.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    result.clear();
    path.clear();
    vector<bool> used(candidates.size(), false);
    std::sort(candidates.begin(), candidates.end());
    backtracking(candidates, target, 0, 0, used);
    return result;
}
#endif //DATASTRUCTURE_COMBINATIONSUM2_H

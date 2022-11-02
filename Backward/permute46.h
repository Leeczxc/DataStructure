//
// Created by Lee on 2022/11/1.
//

#ifndef DATASTRUCTURE_PERMUTE46_H
#define DATASTRUCTURE_PERMUTE46_H
#include "iostream"
#include "vector"

using namespace std;

vector<vector<int>> result;
vector<int> path;

void backtracking(vector<int>& nums, vector<bool>& used){
    if(path.size() == nums.size()){
        result.emplace_back(path);
        return;
    }
    for(int i = 0 ; i < nums.size(); i++){
        if(!used[i]){
            path.emplace_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    result.clear();
    path.clear();
    vector<bool> used(nums.size(), false);
    backtracking(nums, used);
    return result;
}
#endif //DATASTRUCTURE_PERMUTE46_H

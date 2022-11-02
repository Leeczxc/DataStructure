//
// Created by Lee on 2022/11/1.
//

#ifndef DATASTRUCTURE_PERMUTEUNIQUE47_H
#define DATASTRUCTURE_PERMUTEUNIQUE47_H
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

vector<vector<int>> result;
vector<int> path;

void backtracking(vector<int>&nums, vector<bool>& used){
    if(nums.size() == path.size()){
        result.emplace_back(path);
        return;
    }
    for(int i = 0; i < nums.size(); i++){
        if(i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
            continue;
        if(used[i] == false){
            used[i] = true;
            path.emplace_back(nums[i]);
            backtracking(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    result.clear();
    path.clear();
    vector<bool> used(nums.size(), false);
    std::sort(nums.begin(), nums.end());
    backtracking(nums, used);
    return result;
}
#endif //DATASTRUCTURE_PERMUTEUNIQUE47_H

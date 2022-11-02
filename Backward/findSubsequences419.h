//
// Created by Lee on 2022/11/1.
//

#ifndef DATASTRUCTURE_FINDSUBSEQUENCES419_H
#define DATASTRUCTURE_FINDSUBSEQUENCES419_H
#include "iostream"
#include "vector"
#include "unordered_set"

using namespace std;

vector<vector<int>> result;
vector<int> path;

void backtracking(vector<int>& nums, int startIndex){
    if(path.size() > 1)
        result.emplace_back(path);
    unordered_set<int> uset;
    for(int i = startIndex; i < nums.size(); i++){
        if((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end())
            continue;
        uset.insert(nums[i]);
        path.emplace_back(nums[i]);
        backtracking(nums, i  + 1);
        path.pop_back();
    }
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    result.clear();
    path.clear();
    backtracking(nums, 0);
    return result;
}
#endif //DATASTRUCTURE_FINDSUBSEQUENCES419_H

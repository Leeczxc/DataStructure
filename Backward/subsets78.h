//
// Created by Lee on 2022/11/1.
//

#ifndef DATASTRUCTURE_SUBSETS78_H
#define DATASTRUCTURE_SUBSETS78_H
#include "iostream"
#include "vector"

using namespace std;

vector<vector<int>> result;
vector<int> path;

void backtracking(vector<int>& nums, int startIndex){
    result.emplace_back(path);
    if(startIndex == nums.size())
        return;
    for(int i = startIndex; i < nums.size(); i++){
        path.emplace_back(nums[i]);
        backtracking(nums, i + 1);
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    if(nums.size() == 0)
        return vector<vector<int>>();
    result.clear();
    path.clear();
    backtracking(nums, 0);
    return result;
}
#endif //DATASTRUCTURE_SUBSETS78_H

//
// Created by Lee on 2022/11/1.
//

#ifndef DATASTRUCTURE_SUBSETSWITHDUP90_H
#define DATASTRUCTURE_SUBSETSWITHDUP90_H
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

vector<vector<int>> result;
vector<int>path;

void backtracking(vector<int>& nums, int startIndex, vector<bool>& nu){
    result.emplace_back(path);
    if(startIndex >= nums.size())
        return;
    for(int i = startIndex; i < nums.size(); i++){
        if(i > 0 && nums[i] == nums[i - 1] && !nu[i - 1])
            continue;
        path.emplace_back(nums[i]);
        nu[i] = true;
        backtracking(nums, i + 1, nu);
        nu[i] = false;
        path.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    if(nums.size() == 0)
        return vector<vector<int>>();
    vector<bool> nu(nums.size(), false);
    std::sort(nums.begin(), nums.end());
    result.clear();
    path.clear();
    backtracking(nums, 0, nu);
    return result;
}
#endif //DATASTRUCTURE_SUBSETSWITHDUP90_H

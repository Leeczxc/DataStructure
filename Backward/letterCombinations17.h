//
// Created by Lee on 2022/10/31.
//

#ifndef DATASTRUCTURE_LETTERCOMBINATIONS17_H
#define DATASTRUCTURE_LETTERCOMBINATIONS17_H
#include "iostream"
#include "vector"

using namespace std;

vector<string> result;
string path;

void backtracking(int pos, vector<int>& nums){
    if(path.size() == nums.size()){
        result.emplace_back(path);
        return;
    }
    size_t size = nums.size();
    for(int i = pos; i < size; i++){
        for(int j = 0; j < 3; j++){
            path.insert(path.end(), 'a' + (nums[i] - 2) * 3 + j);
            backtracking(i + 1, nums);
            path.erase(path.end() - 1);
        }
    }
}
vector<string> letterCombinations(string digits) {
    vector<int> nums;
    for(auto c : digits)
        nums.emplace_back(c - '0');
    backtracking(0, nums);
    return result;
}
#endif //DATASTRUCTURE_LETTERCOMBINATIONS17_H

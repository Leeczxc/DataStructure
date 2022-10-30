//
// Created by Lee on 2022/10/26.
//

#ifndef DATASTRUCTURE_COMBINATIONSUM4377_H
#define DATASTRUCTURE_COMBINATIONSUM4377_H
#include "iostream"
#include "vector"

using namespace std;

int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= target; i++)
        for(int j = 0; j < nums.size(); j++){
            if(i >= nums[j] && dp[i] < INT_MAX - dp[i - nums[j]])
                dp[i] += dp[i - nums[j]];
        }
    return dp[target];
}
#endif //DATASTRUCTURE_COMBINATIONSUM4377_H

//
// Created by Lee on 2022/10/25.
//

#ifndef DATASTRUCTURE_FINDTARGETSUMWAYS494_H
#define DATASTRUCTURE_FINDTARGETSUMWAYS494_H
#include "iostream"
#include "vector"

using namespace std;

int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for(int x : nums){
        sum += x;
    }
    if(abs(target) > sum)
        return 0;
    if((target + sum) % 2 == 1)
        return false;
    int newTarget = (target + sum) / 2;
    vector<int> dp(newTarget + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < nums.size(); i++)
        for(int j = newTarget; j >= nums[i]; j--){
            dp[j] += dp[j - nums[i]];
        }
    return dp[newTarget];
}
#endif //DATASTRUCTURE_FINDTARGETSUMWAYS494_H

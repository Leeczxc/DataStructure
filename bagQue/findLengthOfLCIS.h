//
// Created by Lee on 2022/10/28.
//

#ifndef DATASTRUCTURE_FINDLENGTHOFLCIS_H
#define DATASTRUCTURE_FINDLENGTHOFLCIS_H
#include "iostream"
#include "vector"

using namespace std;

int findLengthOfLCIS(vector<int>& nums) {
    if(nums.size() <= 1)
        return nums.size();
    int result = 1;
    vector<int> dp(nums.size(),1);
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] > nums[i - 1])
            dp[i] = dp[i - 1] + 1;
        else
            dp[i] = 1;
        if(dp[i] > result)
            result = dp[i];
    }
    return result;
}
#endif //DATASTRUCTURE_FINDLENGTHOFLCIS_H

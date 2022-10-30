//
// Created by Lee on 2022/10/25.
//

#ifndef DATASTRUCTURE_CANPARTITION416_H
#define DATASTRUCTURE_CANPARTITION416_H
#include "iostream"
#include "vector"

using namespace std;
bool getPart(vector<int>& nums, int target){
    vector<int> ans(target + 1, 0);
    for(int i = 0; i < nums.size(); i++)
        for(int j = target; j >= nums[i]; j--){
            ans[j] = max(ans[j], ans[j - nums[i]] + nums[i]);
            if(ans[j] == target)
                return true;
        }
    return false;
}

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for(int x : nums){
        sum += x;
    }
    if(sum % 2 == 1)
        return false;
    return getPart(nums, sum / 2);
}
#endif //DATASTRUCTURE_CANPARTITION416_H

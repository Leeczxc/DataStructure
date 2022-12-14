//
// Created by Lee on 2022/10/28.
//

#ifndef DATASTRUCTURE_FINDLENGTH718_H
#define DATASTRUCTURE_FINDLENGTH718_H
#include "iostream"
#include "vector"

using namespace std;

int findLength(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
    int result = 0;
    for(int i = 0; i < nums1.size(); i++)
        for(int j = 0; j < nums2.size(); j++){
            if(nums1[i] == nums2[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            if(dp[i + 1][j + 1] > result)
                result = dp[i + 1][j + 1];
        }
    return result;
}
#endif //DATASTRUCTURE_FINDLENGTH718_H

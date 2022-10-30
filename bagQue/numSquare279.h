//
// Created by Lee on 2022/10/26.
//

#ifndef DATASTRUCTURE_NUMSQUARE279_H
#define DATASTRUCTURE_NUMSQUARE279_H
#include "iostream"
#include "vector"

using namespace std;

int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j * j <= i; j++){
            if(i - j* j >= 0)
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    if(dp[n] == INT_MAX)
        return -1;
    return dp[n];
}
#endif //DATASTRUCTURE_NUMSQUARE279_H

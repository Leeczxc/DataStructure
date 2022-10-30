//
// Created by Lee on 2022/10/28.
//

#ifndef DATASTRUCTURE_MAXPROFIT122_H
#define DATASTRUCTURE_MAXPROFIT122_H
#include "iostream"
#include "vector"

using namespace std;

int maxProfit(vector<int>& prices) {
    int len = prices.size();
    vector<vector<int>> dp(len, vector<int>(2));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for(int i = 1; i < len; i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    return dp[len - 1][1];
}
#endif //DATASTRUCTURE_MAXPROFIT122_H

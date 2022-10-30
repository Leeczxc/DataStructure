//
// Created by Lee on 2022/10/26.
//

#ifndef DATASTRUCTURE_CHANGE518_H
#define DATASTRUCTURE_CHANGE518_H
#include "iostream"

#include "vector"

using namespace std;

int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < coins.size(); i++)
        for(int j = coins[i]; j <= amount; j++)
            dp[j] += dp[j - coins[i]];
    return dp[amount];
}
#endif //DATASTRUCTURE_CHANGE518_H

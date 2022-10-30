//
// Created by Lee on 2022/10/26.
//

#ifndef DATASTRUCTURE_COINCHANGE_H
#define DATASTRUCTURE_COINCHANGE_H
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int coinChange(vector<int>& coins, int amount) {
   vector<int> dp(amount + 1, INT_MAX);
   dp[0] = 0;
   for(int i = 0; i < coins.size(); i++)
       for(int j = coins[i]; j <= amount; j++){
           if(dp[j - coins[i]] != INT_MAX)
               dp[j] = min(dp[j], dp[j - coins[i]] + 1);
       }
   if(dp[amount] == INT_MAX)
       return -1;
   return dp[amount];
}
#endif //DATASTRUCTURE_COINCHANGE_H

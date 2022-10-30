//
// Created by Lee on 2022/10/25.
//

#ifndef DATASTRUCTURE_ZEROONEBAG_H
#define DATASTRUCTURE_ZEROONEBAG_H
#include "iostream"
#include "vector"

using namespace std;
// 二维数组
int getTheMostValues(vector<int> weights, vector<int> values, int bagWeight){
    vector<vector<int>> ans{weights.size(), vector<int>(bagWeight + 1, 0)};
    for(int i = weights[0]; i <= bagWeight; i++){
        ans[0][i] = values[0];
    }
    for(int i = 1; i < weights.size(); i++){
        for(int j = 0; j <= bagWeight; j++){
            if(j < weights[i])
                ans[i][j] = ans[i - 1][j];
            else
                ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - weights[i]] + values[i]);
        }
    }
    return ans[weights.size() -1 ][bagWeight];
}

// 已为数组
int getBagOne(vector<int> weights, vector<int> values, int bagWeight){
    vector<int> ans(bagWeight + 1, 0);
    for(int i = 0; i < weights.size(); i++){
        for(int j = bagWeight; j >= weights[i]; j--){
            ans[j] = max(ans[j], ans[j - weights[i]] + values[i]);
        }
    }
    return ans[bagWeight];
}
#endif //DATASTRUCTURE_ZEROONEBAG_H

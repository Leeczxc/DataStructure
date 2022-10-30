//
// Created by Lee on 2022/10/25.
//

#ifndef DATASTRUCTURE_FINDMAXFORM_H
#define DATASTRUCTURE_FINDMAXFORM_H
#include "iostream"
#include "vector"
#include "string"

using namespace std;

pair<int, int> getTheOneAndZero(string& str){
    int one = 0;
    int zero = 0;
    for(auto c : str){
        if(c == '0')
            zero++;
        else
            one++;
    }
    return pair(one, zero);
}

int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for(auto str: strs){
        auto temp = getTheOneAndZero(str);
        int one= temp.first;
        int zero = temp.second;
        for(int i = m ; i >= zero; i--)
            for(int j = n; j >= one; j--)
                dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
    }
    return dp[m][n];
}
#endif //DATASTRUCTURE_FINDMAXFORM_H

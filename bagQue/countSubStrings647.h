//
// Created by Lee on 2022/10/30.
//

#ifndef DATASTRUCTURE_COUNTSUBSTRINGS647_H
#define DATASTRUCTURE_COUNTSUBSTRINGS647_H
#include "iostream"
#include "vector"

using namespace std;

int countSubstrings(string s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), false));
    int ans = 0;
    for(int i = s.size() -1; i >= 0 ; i--)
        for(int j = i; j < s.size(); j++){
            if(s[i] == s[j] && ())
        }
    return ans;
}
#endif //DATASTRUCTURE_COUNTSUBSTRINGS647_H

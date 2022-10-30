//
// Created by Lee on 2022/10/28.
//

#ifndef DATASTRUCTURE_WORDBREAK_H
#define DATASTRUCTURE_WORDBREAK_H
#include "iostream"
#include "vector"
#include "unordered_set"

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> words(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for(int i = 1; i <= s.size(); i++)
        for(int j = 0; j < i; j++){
            string word = s.substr(j, i - j);
            if(words.find(word) != words.end() && dp[j])
                dp[i] = true;
        }
    return dp[s.size()];
}
#endif //DATASTRUCTURE_WORDBREAK_H

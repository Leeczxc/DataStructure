//
// Created by Lee on 2022/11/2.
//

#ifndef DATASTRUCTURE_SOLVESUDOKU37_H
#define DATASTRUCTURE_SOLVESUDOKU37_H
#include "iostream"
#include "vector"

using namespace std;

bool isValid(int row, int col, char val, vector<vector<char>>& board){
    for(int i = 0; i < board.size(); i++){
        if(board[row][i] == val)
            return false;
    }
    for(int j = 0; j < board.size(); j++)
        if(board[j][col] == val)
            return false;
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for(int i = startRow; i < startRow + 3; i++)
        for(int j = startCol; j < startCol + 3; j++)
            if(board[i][j] == val)
                return false;
    return true;
};

bool backtracking(vector<vector<char>>& board){
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board.size(); j++){
            if(board[i][j] != '.')
                continue;
            for(char k = '1'; k <= '9'; k++){
                if(isValid(i, j, k, board)){
                    board[i][j] = k;
                    if(backtracking(board))
                        return true;
                    board[i][j] = '.';
                }
            }
            return false;
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    backtracking(board);
}
#endif //DATASTRUCTURE_SOLVESUDOKU37_H

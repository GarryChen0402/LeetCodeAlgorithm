#include "header.h"
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> tmp(m, vector<int>(n));

        auto checkLiveCellCount = [&](int row, int col){
            int cnt = 0;
            for(int i=-1;i<=1;i++){
                if(i + row < 0 || i + row >= m)continue;
                for(int j=-1;j<=1;j++){
                    if(j + col < 0 || j + col >= n)continue;
                    if(i == 0 && j == 0)continue;
                    if(board[i + row][j + col] == 1)cnt++;
                }
            }
            return cnt;
        };


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count = checkLiveCellCount(i, j);
                if(board[i][j] == 1){
                    if(count < 2)tmp[i][j] = -1;
                    else if(count <= 3)tmp[i][j] = 0;
                    else tmp[i][j] = -1;
                }else {
                    if(count == 3)tmp[i][j] = 1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j] += tmp[i][j];
            }
        }
    }
};
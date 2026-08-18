#include "header.h"
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> colCnt;
        unordered_set<int> rowCnt;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    rowCnt.insert(i); colCnt.insert(j);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(colCnt.count(j) || rowCnt.count(i)){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
#include "header.h"
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int steps[4][2] = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };

        int m = matrix.size();
        if(m==0)return {};
        int n = matrix[0].size();
        if(n == 0)return {};
        int cur_step = 0;
        vector<int> ans;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int i = 0, j = 0;
        while(ans.size() < m * n){
            if(visited[i][j] == 0){
                ans.push_back(matrix[i][j]);
                visited[i][j] = 1;
            }
            int ni = i + steps[cur_step][0];
            int nj = j + steps[cur_step][1];
            if(ni < m && ni >=0 && nj >=0 && nj < n && visited[ni][nj] == 0){
                i = ni;
                j = nj;
            }else{
                cur_step = (cur_step + 1) % 4;
            }
        }
        return ans;
    }
};
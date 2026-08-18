#include "header.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int Size = 9;
        vector<unordered_set<char>> cnt(Size * 3);
        for(int i =0;i<Size;i++){
            for(int j=0;j<Size;j++){
                char ch = board[i][j];
                if(ch == '.')continue;
                int rowIdx = i;
                int colIdx = j + 9;
                int gridId = i / 3 * 3 + j / 3 + 18;
                
                if(cnt[rowIdx].count(ch) || cnt[colIdx].count(ch) || cnt[gridId].count(ch))return false;
                else {
                    cnt[rowIdx].insert(ch);
                    cnt[colIdx].insert(ch);
                    cnt[gridId].insert(ch);
                }
            }
        }
        return true;
    }
};
#include "header.h"
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)return s;
        vector<string> tmp(numRows, string(s.size(), ' '));
        int stepX = 0;
        int stepY = 1;
        int curX = 0;
        int curY = 0;
        for(int i=0;i<s.size();i++){
            tmp[curY][curX] = s[i];
            if(curY == numRows - 1){
                stepX = 1;
                stepY = -1;
            }else if(curY == 0){
                stepX = 0;
                stepY = 1;
            }

            curX += stepX;
            curY += stepY;
        }

        int cur = 0;
        for(int i=0;i<numRows;i++){
            for(int j=0;j<tmp[i].size();j++){
                if(tmp[i][j] == ' ')continue;
                else s[cur++] = tmp[i][j];
            }
        }
        return s;
    }
};
#include "header.h"
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cntW = INT_MAX;
        int tmp = 0;
        for(int i=0;i<blocks.size();i++){
            tmp += (blocks[i] == 'W') ? 1 : 0;
            if(i >= k)tmp -= (blocks[i - k] == 'W') ? 1 : 0;
            if(i >= k - 1)cntW = min(cntW, tmp);
        }
        return cntW;
    }
};
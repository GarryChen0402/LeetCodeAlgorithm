#include "header.h"
class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while(n){
            cnt += ((n&3)+1)>>1;
            n>>=2;
        }
        return cnt;
    }
};
#include "header.h"
class Solution 
{
public:
    int kthDigit(long long k){
        k-=1;
        int len = 0;
        long long preLength = 0;
        while(k > preLength){
            preLength += 9 * (long long)pow(10, len);
            len++;
        }
        k -= preLength;
        int num = k / len;
        int lef = k % len;
        
    }
};
#include "../header.h"

class Solution {
public:
    int smallestNumber(int n, int t) {
        auto compute = [](int x){
            int ans = 1;
            while(x > 1){
                ans *= x % 10;
                x /= 10;
            }
            return ans;
        };
        for(int x = n;x <= 100;x++){
            int tmp = compute(x);
            if(tmp % t == 0)return x;
        }
        return n;
    }
};
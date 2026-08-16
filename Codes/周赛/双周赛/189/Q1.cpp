#include "header.h"

class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int cur = 0;
        int ans = 0;
        for(int& num : requests){
            ans += abs(cur - num);
            cur = num;
        }
        return ans;
    }
};
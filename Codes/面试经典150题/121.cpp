#include "header.h"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pm = prices[0];
        int ans = 0;
        for(int& num : prices){
            ans = max(ans, num - pm);
            pm = min(pm, num);
        }
        return ans;
    }
};
#include "header.h"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 1. 分割为多个单调上升子区间， 每个区间按照121 求解， 最终求和
        // int pm = INT_MAX;
        // int ans = INT_MIN;
        // int sum = 0;
        // int n = prices.size();
        // for(int i=0;i<n;i++){
        //     if(i == 0){
        //         pm = min(pm, prices[i]); ans = 0;
        //     }else {
        //         ans = max(ans, prices[i] - pm);
        //         if(prices[i] > prices[i-1] && (i == n-1 || prices[i] >= prices[i+1])){
        //             sum += ans;
        //             pm = INT_MAX;
        //             ans = INT_MIN;
        //         }else{
        //             pm = min(pm, prices[i]);
        //         }
        //     }
        // }
        // 2. 贪心
        int sum = 0;
        for(int i=1;i<prices.size();i++)sum += max(0, prices[i] - prices[i-1]);
        return sum;
    }
};
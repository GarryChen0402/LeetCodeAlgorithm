#include "header.h"
class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int ans = 0, n = calories.size(), tmp = 0;
        for(int i=0;i<n;i++){
            tmp += calories[i];
            if(i >= k)tmp -= calories[i-k];
            if(i >= k-1){
                if(tmp < lower)ans--;
                else if(tmp > upper)ans++;
            }
        }
        return ans;
    }
};
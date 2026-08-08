#include "header.h"

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        long long tmp = 0, range = k * 2 + 1;
        if(range > n)return ans;
        for(int i=0;i<n;i++){
            tmp += nums[i];
            if(i >= range)tmp -= nums[i- range];
            if(i >= range - 1)ans[i - k] = tmp / range;
        }
        return ans;
    }
};
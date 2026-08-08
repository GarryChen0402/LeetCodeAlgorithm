#include "header.h"

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int cnt = INT_MIN;
        int tmp = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            tmp += nums[i];
            if(i >= k)tmp -= nums[i-k];
            if(i >= k - 1)cnt = max(cnt, tmp);
        }
        return static_cast<double>(cnt) / static_cast<double>(k);
    }
};
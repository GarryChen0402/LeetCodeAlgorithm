#include "header.h"
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0 ,  r = 0;
        int ans = n+1;
        int tmp = 0;
        while(r < n){
            tmp += nums[r];
            while(tmp >= target){
                ans = min(ans, r- l + 1);
                tmp -= nums[l++];
            }
            r++;
        }
        return ans == n+1 ? 0 : ans;
    }
};
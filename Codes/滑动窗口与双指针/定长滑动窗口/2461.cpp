#include "header.h"
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        long long ans = 0, tmp = 0;
        unordered_map<int, int> count;
        for(int i=0;i<n;i++){
            int ni = nums[i];
            count[ni]++;
            tmp += ni;
            cnt += (count[ni] == 1) ? 1 : 0;
            if(i >= k){
                int nj = nums[i-k];
                if(count[nj]==1)cnt--;
                count[nj]--;
                tmp -= nj;
            }
            if(i >= k - 1 && cnt == k){
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};
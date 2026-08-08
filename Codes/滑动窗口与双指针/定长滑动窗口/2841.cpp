#include "header.h"
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int cnt = 0;
        unordered_map<int, int> count;
        long long ans = 0;
        long long tmp = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            count[nums[i]]++;
            if(count[nums[i]] == 1)cnt++;
            tmp += nums[i];
            if(i >= k){
                int nj = nums[i-k];
                tmp -= nj;
                count[nj]--;
                if(count[nj] == 0)cnt--;
            }
            if(i >= k - 1 && cnt >= m){
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};
#include "header.h"
class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, int k) {
        long long ans = 0;
        long long tmp = 0;
        unordered_map<int, int> cnt;
        int n = nums.size();
        constexpr int MOD = 1e9 + 7;

        auto modPow = [MOD](long long k, long long m){
            long long ans = 1;
            k %= MOD;
            while(m){
                if(m&1)ans = ans * k % MOD;
                k = k * k % MOD;
                m >>= 1;
            }
            return ans;
        };

        for(int i=0;i<n;i++){
            int ni = nums[i];
            cnt[ni]++;
            if(cnt[ni] == 1)tmp = (tmp + ni) % MOD;
            else tmp = (tmp + modPow(ni, cnt[ni]-1) * (ni - 1)) % MOD;
            if(i >= k){
                int nj = nums[i-k];
                cnt[nj] --;
                if(cnt[nj]==0)tmp = (tmp - nj + MOD) % MOD;
                else tmp = (tmp - modPow(nj, cnt[nj]) * (nj - 1) % MOD + MOD) % MOD;
            }

            if(i >= k- 1)ans = max(ans, tmp);
        }
        return ans;
    }
};
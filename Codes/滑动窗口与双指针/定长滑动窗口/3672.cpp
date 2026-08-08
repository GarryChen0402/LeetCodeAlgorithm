#include "header.h"
class Solution {
public:
    long long modeWeight(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        set<pair<int, int>> s;  // (-frequency, element), begin() = max freq + min element
        long long ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (cnt[x] > 0) s.erase({-cnt[x], x});
            cnt[x]++;
            s.insert({-cnt[x], x});

            if (i >= k) {
                int y = nums[i - k];
                s.erase({-cnt[y], y});
                cnt[y]--;
                if (cnt[y] > 0) s.insert({-cnt[y], y});
            }

            if (i >= k - 1) {
                auto [freq, key] = *s.begin();
                ans += (long long)(-freq) * key;
            }
        }
        return ans;
    }
};
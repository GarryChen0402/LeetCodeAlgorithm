#include "header.h"
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.size();
        int cnt[128] = {};
        auto check = [&](){
            for(int i=0;i<128;i++)
                if(cnt[i] > 1)return false;
            return true;
        };
        int ans = 0;
        while(r < n){
            cnt[s[r]]++;
            while(!check()){
                cnt[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};
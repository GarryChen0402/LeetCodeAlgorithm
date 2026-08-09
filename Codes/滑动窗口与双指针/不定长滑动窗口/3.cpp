#include "header.h"
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), l = 0, r = 0; // [l, r)
        unordered_set<char> cnt;
        int ans = 0;
        while(r < n){
            char cur = s[r];
            if(!cnt.count(cur)){
                r++;
                cnt.insert(cur);
            }
            else {
                ans = max(ans, r - l);
                while(l < r && s[l] != cur ){
                    cnt.erase(s[l]);l++;
                }
                l++;
                r++;
            }
        }
        ans = max(ans, r - l);
        return ans;
    }
};
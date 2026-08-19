#include "header.h"
class Solution {
public:
    string minWindow(string s, string t) {
        int cntT[128] = {};
        for(char& ch : t)cntT[ch] ++;
        int cntS[128] = {};
        auto check = [&](){
            for(int i=0;i<128;i++){
                if(cntS[i] < cntT[i])return false;
            }
            return true;
        };

        string ans = "";
        int l = 0;
        int r = 0;
        while(r < s.size()){
            cntS[s[r]]++;
            while(check()){
                if(ans.empty() || ans.size() >= r - l + 1)ans = s.substr(l , r+1 - l);
                cntS[s[l]]--;
                l++;
            }
            r++;
        }
        if(check() && ans.size() >= r - l)ans = s.substr(l ,r -l);
        return ans;
    }
};
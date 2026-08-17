#include "header.h"
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](string a, string b){
            return a.size() < b.size();
        });
        int cur = 0;
        int n = strs.size();
        auto check = [&](int idx){
            if(idx >= strs[0].size())return false;
            char ch = strs[0][idx];
            for(int i=1;i<n;i++){
                if(strs[i][idx] != ch)return false;
            }
            return true;
        };

        while(check(cur)){
            cur++;
        }
        return strs[0].substr(0, cur);
    }
};
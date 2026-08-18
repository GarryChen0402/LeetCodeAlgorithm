#include "header.h"
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(t.empty() && !s.empty())return false;
        if(s.empty())return true;

        int cs = 0;
        int ns = s.size();
        int ct = 0;
        int nt = t.size();
        while(cs <= ct && cs < ns && ct < nt){
            if(s[cs] == t[ct]){
                cs++;
                ct++;
            }else{
                ct++;
            }
        }

        return cs == ns;
    }
};
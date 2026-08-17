#include "header.h"
class Solution {
public:
    string reverseWords(string s) {
        while(s.back() == ' ')s.pop_back();
        reverse(s.begin(), s.end());
        while(s.back() == ' ')s.pop_back();

        int l = 0;
        int r = 0;
        int n = s.size();
        while(r < n){
            while(r < n && s[r] != ' ')r++;
            reverse(s.begin() + l, s.begin() + r);
            while(r < n && s[r] == ' ')r++;
            l = r;
        }

        int k = 0;
        for(int i=0;i<n;i++){
            if(s[i] != ' ' || (i > 0 && s[i-1] != ' '))
            s[k++] = s[i];
        }
        s.resize(k);
        return s;
    }
};
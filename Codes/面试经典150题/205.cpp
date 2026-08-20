#include "header.h"
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int ns = s.size(), nt = t.size();
        if(ns != nt)return false;
        int map[128] = {};
        unordered_set<char> cnt;
        for(int& n : map)n = -1;

        for(int i=0;i<ns;i++){
            char ch = s[i];
            if(map[ch] == -1){
                if(cnt.count(t[i]))return false;
                map[ch] = t[i];
                cnt.insert(t[i]);
            }
            else if(map[ch] != t[i])return false;
        }
        return true;
    }
};
#include "header.h"
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26] = {};
        for(char& ch : ransomNote)cnt[ch - 'a']--;
        for(char& ch : magazine)cnt[ch - 'a']++;
        for(int& n : cnt)
            if(n < 0)return false;
        return true;
    }
};
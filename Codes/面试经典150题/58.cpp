#include "header.h"
class Solution {
public:
    int lengthOfLastWord(string s) {
        while(s.back() == ' ')s.pop_back();
        int lstSpace = s.size() - 1;
        while(lstSpace >= 0 && s[lstSpace] != ' ')lstSpace--;
        if(lstSpace < 0)return s.size();
        return s.size() - lstSpace - 1;
    }
};
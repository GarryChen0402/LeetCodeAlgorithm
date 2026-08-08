#include "header.h"
class Solution {
public:
    int maxVowels(string s, int k) {
        int cnt = 0;
        auto Count = [](char ch){
            static unordered_set<char> table = {'a', 'e', 'i', 'o', 'u'};
            return table.count(ch);
        };

        int n = s.size();
        int tmp = 0;
        for(int i=0;i<n;i++){
            tmp += Count(s[i]);
            if(i >= k)tmp -= Count(s[i-k]);
            cnt = max(cnt, tmp);
        }
        return cnt;
    }
};
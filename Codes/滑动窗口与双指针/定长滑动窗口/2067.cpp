#include "header.h"
class Solution {
public:
    int equalCountSubstrings(string s, int count) {
        int ans = 0;
        int n = s.size();
        int maxK = min(n, count * 26);
        for(int k = count; k <= maxK;k+=count){
            int table[26] = {};
            int cntC = 0, cntZ=26;
            for(int i=0;i<n;i++){
                char ch = s[i];
                if(table[ch - 'a'] == 0 )cntZ--;
                table[ch]++;
                if(table[ch - 'a'] == count)cntC++;

                if(i >= k){
                    char c1 = s[i-k];
                    table[c1- 'a']--;
                    if(table[c1- 'a'] == 0)cntZ++;
                    if(table[c1- 'a'] == count - 1)cntC--;
                }

                if(i >= k - 1){
                    if(26 - cntZ == cntC && cntC * count == k)ans++;
                }
            }
        }
        return ans;
    }
};


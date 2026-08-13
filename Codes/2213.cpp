#include "header.h"
class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        //待解决， 超时
        int n = s.size();
        int qn = queryCharacters.size();
        auto computeAns = [&](){
            int l = 0;
            int r = 1;
            int m = 0;
            while(r < n){
                if(s[l] == s[r])r++;
                else {
                    m = max(m, r - l);
                    l = r;
                }

            }
            m = max(m, r- l);
            return m;
        };

        vector<int> ans(qn);
        for(int i=0;i<qn;i++){
            s[queryIndices[i]] = queryCharacters[i];
            ans[i] = computeAns();
        }
        return ans;
    }
};
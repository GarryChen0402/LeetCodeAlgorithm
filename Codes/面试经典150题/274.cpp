#include "header.h"
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> h(n+1);
        for(int& c : citations)h[min(c, n)]++;
        int sufSum = 0;
        for(int i=n;i>=0;i--){
            sufSum += h[i];
            if(sufSum >= i)return i;
        }
        return 0;
    }
};
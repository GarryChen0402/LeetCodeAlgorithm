#include "header.h"
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n - 1;
        while(l <= r){
            int m = l + (r - l ) / 2;
            int km = n - m;
            int cm = citations[m];
            if(km >= cm)l = m + 1;
            else r = m - 1;
        }
        if (r == -1) return n - l;
        return max(n - l , citations[r]);
    }
};
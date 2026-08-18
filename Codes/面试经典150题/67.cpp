#include "header.h"
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int la = a.size();
        int lb = b.size();
        if(la >= lb){
            swap(la, lb);
            swap(a, b);
        }

        for(int i=0;i<la;i++){
            b[i] += a[i] - '0';
        }

        for(int i=0;i<lb;i++){
            int cur = b[i] - '0';
            if(cur <= 1)continue;
            else {
                if(i == lb - 1)b.push_back('0');
                b[i+1] += cur / 2;
                b[i] = '0' + cur % 2;
            }
        }
        reverse(b.begin(), b.end());
        return b;
    }
};
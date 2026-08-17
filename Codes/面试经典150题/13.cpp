#include "header.h"
class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int n = s.size();
        int cur = 0;
        while(cur < n){
            char ch = s[cur];
            if(ch == 'M'){
                cur++;
                sum += 1000;
            }else if(ch == 'D'){
                cur++;
                sum += 500;
            }else if(ch == 'C'){
                cur++;
                if(cur < n && (s[cur] == 'M' || s[cur] == 'D'))sum -= 100;
                else sum += 100;
            }else if(ch == 'L'){
                cur++;
                sum += 50;
            }else if(ch == 'X'){
                cur++;
                if(cur < n && (s[cur] == 'L' || s[cur] == 'C'))sum -= 10;
                else sum += 10;
            }else if(ch == 'V'){
                cur++;
                sum += 5;
            }else if(ch == 'I'){
                cur++;
                if(cur < n && (s[cur] == 'V' || s[cur] == 'X'))sum -= 1;
                else sum += 1;
            }
        }
        return sum;
    }
};
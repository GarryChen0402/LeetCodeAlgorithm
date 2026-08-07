#include "../header.h"
class Solution {
public:
    bool isPalindrome(string s) {
        auto isAlpha = [](char ch){
            return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
        };

        auto isEqual = [](char a, char b){
            if(a>= 'A' && a <= 'Z')a += 'a' - 'A';
            if(b>= 'A' && b <= 'Z')b += 'a' - 'A';
            return a == b;
        };

        int n = s.size();
        int l = 0, r = n - 1;
        while(l <= r){
            char a = s[l];
            char b = s[r];
            if(!isAlpha(a))l++;
            else if(!isAlpha(b))r--;
            else {
                if(!isEqual(a, b))return false;
                else {
                    l++;
                    r--;
                }
            }
        };
        return true;
    }
};
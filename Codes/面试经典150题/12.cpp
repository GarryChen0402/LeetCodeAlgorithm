#include "header.h"
class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        while(num >= 1000){
            ans.push_back('M');
            num -= 1000;
        }
        if(num >= 900){
            num -= 900;
            ans.push_back('C');
            ans.push_back('M');
        }else if(num >= 500){
            num -= 500;
            ans.push_back('D');
        }else if(num >= 400){
            num -= 400;
            ans.push_back('C');
            ans.push_back('D');
        }
        while(num >= 100){
            num -= 100;
            ans.push_back('C');
        }
        if(num >= 90){
            num -= 90;
            ans.push_back('X');
            ans.push_back('C');
        }else if(num >= 50){
            num -= 50;
            ans.push_back('L');
        }else if(num >= 40){
            num -= 40;
            ans.push_back('X');
            ans.push_back('L');
        }
        while(num >= 10){
            num -= 10;
            ans.push_back('X');
        }

        if(num >= 9){
            num -= 9;
            ans.push_back('I');
            ans.push_back('X');
        }else if(num >= 5){
            num -= 5;
            ans.push_back('V');
        }else if(num >= 4){
            num -= 4;
            ans.push_back('I');
            ans.push_back('V');
        }
        while(num >= 1){
            num -= 1;
            ans.push_back('I');
        }
        return ans;

    }
};
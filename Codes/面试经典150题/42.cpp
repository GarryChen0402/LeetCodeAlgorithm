#include "header.h"
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l = 0;
        int r = n - 1;
        int preL = height[l];
        int preR = height[r];
        while(l <= r){
            preL = max(preL, height[l]);
            preR = max(preR, height[r]);
            if(preL < preR){
                ans += (preL - height[l]);
                l++;
            }else{
                ans += (preR - height[r]);
                r--;
            }
        }
        return ans;
    }
};
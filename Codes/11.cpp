#include "../header.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int l = 0;
        int r = n - 1;
        while(l < r){
            int tmp = min(height[l], height[r]) * (r - l); 
            ans = max(ans, tmp);
            if(height[l] < height[r])l++;
            else r--;
        }
        return ans;
    }
};
#include "header.h"
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = nums[0]; bool allZero = true;
        for(int i=1;i<nums.size();i++){
            ans ^= nums[i];
            if(allZero && nums[i] != 0)allZero = false;
        }
        if(allZero)return 0;
        if(ans == 0)return nums.size() - 1;
        else return nums.size();
    }
};
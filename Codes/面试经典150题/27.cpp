#include "header.h"
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            if(nums[r] == val)r--;
            else if(nums[l] == val)swap(nums[l++], nums[r--]);
            else l++;
        }
        return l;
    }
};
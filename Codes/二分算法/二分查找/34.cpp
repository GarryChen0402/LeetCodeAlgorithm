#include "header.h"
class Solution {
public:
    int lower_bound(vector<int>& nums, int target){ // first element >= target
        int n = nums.size();
        int l = 0, r = n - 1;
        int ans = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] >= target)r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }

    int upper_bound(vector<int>& nums, int target){// first element > target
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l <= r){
            int m = l + (r - l) /2;
            if(nums[m] > target)r = m - 1;
            else l = m + 1;
        }
        return l;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int firstIdx = lower_bound(nums, target);
        if(nums.size() == 0 || firstIdx >= nums.size() || firstIdx < 0 || nums[firstIdx] != target)return {-1, -1};
        return {firstIdx, upper_bound(nums, target)-1};
    }
};
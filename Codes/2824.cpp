#include "../header.h"
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        // 暴力
        int cnt = 0;
        int n = nums.size();
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i] + nums[j] < target)cnt++;
        //     }
        // }
        // 双指针
        sort(nums.begin(), nums.end());
        int l = 0, r = n - 1;
        while (l < r){
            int tmp = nums[l] + nums[r];
            if(tmp < target){
                cnt += (r - l);
                l++;
            }else{
                r--;
            }
        }
        return cnt;
    }
};
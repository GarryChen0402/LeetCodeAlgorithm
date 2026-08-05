#include "../header.h"

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int n = nums.size();
        for(int i=2;i<n;i++){
            int x = nums[i];

            int l = 0;
            int r = i-1;
            while(l < r){
                int tmp = nums[l] + nums[r];
                if(tmp > x){
                    cnt += (r - l);
                    r--;
                }else{
                    l++;
                }
            }
        }
        return cnt;
    }
};
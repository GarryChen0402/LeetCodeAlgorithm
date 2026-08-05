#include "../header.h"
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 1e5;
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            int l = i+1;
            int r = n-1;

            while (l < r){
                int tmp = nums[i] + nums[l] + nums[r];
                if(tmp == target){
                    ans = tmp;
                    break;
                }else if(tmp > target){
                    r--;
                    if(abs(tmp - target) <= abs(ans - target))ans = tmp;
                }else{
                    l++;
                    if(abs(tmp - target) <= abs(ans - target))ans = tmp;
                }
            }
        }
        return ans;

    }
};
#include "header.h"
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            if(i>0&&nums[i] == nums[i-1])continue;
            int target = -nums[i];
            int l = i+1, r = n - 1;
            while(l < r){
                int tmp = nums[l] + nums[r];
                if(tmp == target){
                    ans.push_back({-target, nums[l], nums[r]});
                    r--;
                    while(l < r && nums[r] == nums[r+1])r--;
                    l++;
                    while(l < r && nums[l] == nums[l-1])l++;
                }else if(tmp > target)r--;
                else l++;
            }
        }
        return ans;
    }
};
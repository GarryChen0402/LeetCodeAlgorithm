#include "../header.h"
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0;i<n-3;i++){
            int  x = nums[i];
            if(i > 0 && nums[i-1] == x)continue;

            for(int j=i+1;j<n-2;j++){
                int y = nums[j];
                if(j>i+1 && y == nums[j-1])continue;

                int l = j+1;
                int r = n-1;

                while(l < r)
                {
                    long long tmp = (long long)nums[l] + (long long)nums[r] + (long long)x + (long long)y;
                    if(tmp == target){
                        ans.push_back({x, y, nums[l], nums[r]});
                        r--;
                        while(r > l && nums[r] == nums[r+1])r--;
                        l++;
                        while(l < r && nums[l] == nums[l-1])l++;

                    }else if(tmp > target)r--;
                    else l++;
                }
            }
        }
        return ans;
    }
};
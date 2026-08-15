#include "header.h"
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, INT_MAX);
        ans[0] = 0;
        for(int i=0;i<n;i++){
            for(int j = 1;j<=nums[i] && j + i < n;j++)
                ans[j + i] = min(ans[j+i], ans[i]+1);
        }
        return ans.back();
    }
};
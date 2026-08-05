#include "../header.h"
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> cnt;
        for(int i=0;i<nums.size();i++){
            int tmp = target - nums[i];
            if(cnt.count(tmp))return {cnt[tmp][0], i};
            else cnt[nums[i]].push_back(i);
        }
        return {0,0};
    }
};
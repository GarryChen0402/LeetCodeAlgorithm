#include "header.h"
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int tmp = nums[0];
        for(int i=0;i<nums.size() && i <= tmp;i++)tmp = max(tmp, i + nums[i]);
        return tmp >= nums.size()-1;
    }
};
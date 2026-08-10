#include "header.h"
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, cnt = 0;// 摩尔投票算法
        for(int num : nums){
            if(cnt == 0)candidate = num;
            cnt += (candidate == num) ? 1 : -1;
        }
        return candidate;
    }
};
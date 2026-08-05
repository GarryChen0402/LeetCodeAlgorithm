#include "../header.h"
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int n = numbers.size();
        int r = n -1;
        while(l < r){
            int s = numbers[l] + numbers[r];
            if(s > target)r--;
            else if(s < target)l++;
            else break;
        }
        return {l+1, r + 1};
    }
};
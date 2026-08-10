#include "header.h"
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int c = 0;
        int w = 0;
        int left = 2;
        while(c < nums.size()){
            if(w == 0){
                nums[w] = nums[c];
                w++;
                left--;
            }else if(nums[c] == nums[w-1]){
                if(left > 0){
                    nums[w] = nums[c];
                    w++;
                    left--;
                }
            }else {
                nums[w] = nums[c];
                w++;
                left = 1;
            }
            c++;
        }
        return w;
    }
};
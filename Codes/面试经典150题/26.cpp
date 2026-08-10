#include "header.h"
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int c = 0;
        int w = 0;
        while(c < nums.size()){
            if(w == 0 || nums[c] != nums[w-1])
                nums[w++] = nums[c];
            c++;
        }
        return w;
    }
};
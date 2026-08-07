#include "../header.h"

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();
        int leftA = capacityA;
        int leftB = capacityB;
        int l = 0, r = n - 1;
        int cnt = 0;
        while( l <= r){
            if(l == r){
                if(max(leftA, leftB) >= plants[l])break;
                else cnt++;
                l++;
                r--;
            }else{
                if(leftA < plants[l]){
                    leftA = capacityA;
                    cnt++;
                }
                leftA -= plants[l];
                l++;

                if(leftB < plants[r]){
                    leftB = capacityB;
                    cnt++;
                }
                leftB -= plants[r];
                r--;
            }
        }
        return cnt;
    }
};
#include "header.h"
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        threshold *= k;
        int cnt =0, tmp = 0;
        for(int i=0;i<arr.size();i++){
            tmp += arr[i];
            if(i >= k)tmp -= arr[i-k];
            if(i >= k - 1 && tmp >= threshold)cnt++;
        }
        return cnt;
    }
};
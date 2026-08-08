#include "header.h"

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int tmp = 0, ans = 0;
        for(int i=0;i<min(n, k);i++)tmp += cardPoints[i];// 求取第一个窗口的结果
        ans = tmp;
        if(k >= n)return ans;
        for(int i=k-1;i>=0;i--){
            tmp -= cardPoints[i];
            tmp += cardPoints[n - k + i];
            ans = max(tmp, ans);
        }
        return ans;
    }
};
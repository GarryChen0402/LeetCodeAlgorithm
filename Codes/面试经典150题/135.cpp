#include "header.h"
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n);
        int sum = n;
        for(int i=0;i<n-1;i++)
        {
            if(ratings[i] == ratings[i+1])continue;
            else if(ratings[i] < ratings[i+1])candies[i+1] = candies[i]+1;
            else candies[i] = candies[i+1] + 1;
        }
        for(int i=n-1;i > 0;i++)
        {
            if(ratings[i] == ratings[i-1])continue;
            else if(ratings[i] < ratings[i-1])candies[i-1] = max(candies[i]+1, candies[i-1]);
            else candies[i] = max(candies[i], candies[i-1] + 1);
        }
        for(int i=0;i<n;i++){
            sum += candies[i];
        }
        return sum;
    }
};
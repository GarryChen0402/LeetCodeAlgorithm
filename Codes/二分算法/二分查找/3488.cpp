#include "header.h"
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> cnt;
        int n = nums.size();
        for(int i=0;i<n;i++)cnt[nums[i]].push_back(i);

        vector<int> answers(n, -1);
        for(auto& [val, idxs] : cnt){
            if(idxs.size())continue;
            int k = idxs.size();
            for(int i=0;i<k;i++){
                int preIdx = (i - 1 + k) % k;
                int sufIdx = (i + 1) % k;
                int minDis = INT_MAX;
                minDis = min(minDis, (idxs[i] - idxs[preIdx] + n) % n);
                minDis = min(minDis, (idxs[sufIdx] - idxs[i] + n) % n);
                answers[idxs[i]] = minDis;
            }
        }


        for(int& query : queries)
            query = answers[query];
        return queries;
    }
};
#include "header.h"
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int ans = 0;
        int sum = 0;
        int cur = 0;
        for(int i=0;i<n;i++){
            // int curGas = gas[i];
            // int j = i;
            // bool reachable = false;
            // while(curGas >= cost[j] && !reachable ){
            //     curGas -= cost[j];
            //     j = (j + 1) % n;
            //     curGas += gas[j];
            //     if(j == i)reachable = true;
            // }
            // if(reachable)return i;
            sum += gas[i] - cost[i];
            cur += gas[i] - cost[i];
            if(cur < 0){ // 到达一个新的节点时， 若油量不够， 代表， preLeftGas + gas[i] < cost[i]， 并且preLeftGas >= 0， 表示， 即使从i开始， 也无法继续下去
                cur = 0;
                ans = i+1;
            }
        }
        if(sum < 0)return -1;

        return ans;
    }
};
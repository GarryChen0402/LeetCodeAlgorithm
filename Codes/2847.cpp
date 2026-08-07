#include "../header.h"
class Solution {
public:
    string smallestNumber(long long n) {
        if(n == 1)return "1";
        vector<long long> mem;
        while(n > 1){
            bool find = false;
            for(int i=9;i>=2 && !find;i--){
                if(n % i == 0){
                    n /= i;
                    find = true;
                    mem.push_back(i);
                }
            }
            if(!find && n > 1)return "-1"; 
        }
        sort(mem.begin(), mem.end());
        string ans;
        for(auto& m : mem)ans.append(to_string(m));
        return ans;
    }
};
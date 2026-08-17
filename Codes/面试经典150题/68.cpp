#include "header.h"
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n =words.size();
        vector<string> ans;
        int l = 0;
        int r = 0;
        while(l <= r && r < n){
            int tmp = 0;
            while(r < n && tmp + words[r].size() + (r - l) <= maxWidth){
                tmp += words[r].size();
                r++;
            }
            string cur(maxWidth, ' ');
            int leftSpace = maxWidth - tmp;
            vector<int> gap(r-l, 0);
            int gaps = (r -l - 1) ? (r - l -1) : 1;
            for(int i=0;i<gaps;i++){
                gap[i] = leftSpace / gaps + (i < leftSpace % gaps);
            }
            // 将字符串铺在cur中
            int curIdx = 0;
            for(int i=l;i<r;i++){
                int j = 0;
                while(j < words[i].size()){
                    cur[curIdx] = words[i][j];
                    curIdx++;
                    j++;
                }
                curIdx += gap[i-l];
            }
            l = r;
            r = l;
            ans.push_back(cur);
        }
        int k = 0;
        for(int i=0;i<ans.back().size();i++){
            if(ans.back()[i] != ' ' || (i > 0 && ans.back()[i-1] != ' '))
                ans.back()[k++]=ans.back()[i];
        }
        for(;k<maxWidth;k++)ans.back()[k] = ' ';
        return ans;
    }
};
#include "header.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx = 1;
        ListNode* pre = head;
        ListNode* cur = head->next;
        if(!cur)return {-1, -1};
        ListNode* nxt = cur->next;
        if(!nxt)return {-1, -1};

        int firstIdx = -1;
        int preIdx = -1;
        
        vector<int> ans = {INT_MAX, INT_MIN};
        bool findSecond = false;
        while(nxt){
            if((long long)(cur->val - pre->val) * (long long)(cur->val - nxt->val) > 0){
                if(firstIdx == -1)firstIdx = idx;
                else ans[1] = max(ans[1], idx - firstIdx);
                
                if(preIdx == -1)preIdx = idx;
                else {
                    ans[0] = min(ans[0], idx - preIdx);
                    preIdx = idx;
                    findSecond = true;
                }
            }
            idx++;
            nxt = nxt->next;
            cur = cur->next;
            pre = pre->next;
        }
        if(findSecond)return ans;
        else return {-1, -1};
    }
};
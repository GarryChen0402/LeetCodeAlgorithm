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
    string gameResult(ListNode* head) {
        ListNode* even = head;
        ListNode* odd = head->next;
        int cnt = 0;
        while(odd){
            if(odd->val > even->val)cnt++;
            else if(odd->val < even->val)cnt--;
            if(!odd->next)break;
            even = odd->next;
            odd = even->next;
        }
        if(cnt < 0)return "Even";
        else if(cnt == 0)return "Tie";
        return "Odd";
    }
};
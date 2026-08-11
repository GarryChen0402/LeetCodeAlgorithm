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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* tmp = head;
        while(tmp){
            n++;
            tmp = tmp->next;
        }
        int a = n / k;
        int b = n % k;
        int left = k - b;
        ListNode* pre = new ListNode(-1, head);
        int cnt = 0;
        vector<ListNode*> ans = {head};
        ListNode* cur = head;
        while(cur){
            cnt++;
            if(b > 0 && cnt == a + 1){
                b--;
                ans.push_back(cur->next);
                cur->next = nullptr;
                cur = ans.back();
                cnt = 0;
            }else if(b == 0 && left > 0 && cnt == a){
                left --;
                if(!cur->next)break;
                ans.push_back(cur->next);
                cur->next = nullptr;
                cur = ans.back();
                cnt = 0;
            }else{
                cur = cur->next;
            }
        }
        while(ans.size() < k)ans.push_back(nullptr);
        return ans;
    }
};
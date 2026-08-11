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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_set<int> cnt;
        unordered_set<int> repeat;
        ListNode* tmp = head;
        while(tmp){
            if(cnt.count(tmp->val))repeat.insert(tmp->val);
            else cnt.insert(tmp->val);
            tmp = tmp->next;
        }
        ListNode* dummy = new ListNode(-1, head);
        tmp = dummy;
        while(tmp->next){
            if(repeat.count(tmp->next->val))tmp->next = tmp->next->next;
            else tmp = tmp->next;
        }
        return dummy->next;
    }
};
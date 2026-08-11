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
    ListNode* frequenciesOfElements(ListNode* head) {
        unordered_map<int, ListNode*> map;
        ListNode* ans = new ListNode();
        while(head){
            int val = head->val;
            if(map.find(val) == map.end()){
                ListNode* n = new ListNode(1);
                n->next = ans->next;
                ans->next = n;
                map[val] = n;
            }else{
                map[val]->val++;
            }
            head = head->next;
        }

        return ans->next;
    }
};
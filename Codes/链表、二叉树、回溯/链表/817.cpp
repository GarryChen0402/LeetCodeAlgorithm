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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> set;
        for(int& num : nums)set.insert(num);

        int cnt = 0;
        bool isInSet = false;
        while(head){
            int val = head->val;
            if(!isInSet && set.count(val))isInSet = true;
            else if(isInSet && !set.count(val)){
                isInSet = false;
                cnt++;
            }
            head = head->next;
        }
        if(isInSet)cnt++;
        return cnt;
    }
};
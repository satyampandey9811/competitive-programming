// link to question - https://leetcode.com/problems/partition-list/

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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *d = new ListNode(-300);
        d -> next = head;
        ListNode *temp = head, *b = d, *prev = d;
        bool f = false;
        
        while(temp) {
            if(temp -> val >= x and !f) {
                f = true;
            }
            if(f and temp -> val < x) {
                ListNode *next = temp -> next;
                prev -> next = next;
                temp -> next = b -> next;
                b -> next = temp;
                b = b -> next;
                temp = prev;
            }
            else prev = prev -> next;
            temp = temp -> next;
            if(!f) b = b -> next;
        }
        
        return d -> next;
    }
};
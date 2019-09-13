// link to question - https://leetcode.com/problems/reverse-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        ListNode* p = reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return p;
    }
};
// link to question - https://leetcode.com/problems/remove-linked-list-elements/

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev=head,*current=head;
        while(current!=NULL){
            if(current==head and current->val==val)
                head=current->next;
            else if(current->val==val){
                prev->next=current->next;
            }
            else
                prev=current;
            current=current->next;
        }
        return head;
    }
};
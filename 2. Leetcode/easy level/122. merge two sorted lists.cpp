// link to question - https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode *head = NULL, *tail, *temp;
        
        while(a and b){
            if(a -> val <= b -> val){
                temp = a;
                a = a -> next;
            }
            else{
                temp = b;
                b = b -> next;
            }
            if(head == NULL)
                head = tail = temp;
            else{
                tail -> next = temp;
                tail = temp;
            }
        }
        
        while(a){
            if(head == NULL)
                head = tail = a;
            else{
                tail -> next = a;
                tail = a;
            }
            a = a -> next;
        }
        
        while(b){
            if(head == NULL)
                head = tail = b;
            else{
                tail -> next = b;
                tail = b;
            }
            b = b -> next;
        }
        
        return head;
    }
};
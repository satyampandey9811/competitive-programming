// link to question - https://leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode* reverse(ListNode *head){
        if(!head or !head -> next)
            return head;
        ListNode *temp = reverse(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return temp;
    }
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n)
            return head;
        ListNode *temp1, *temp2, *start = head, *end = head;
        
        int a = 1, b = 1;
        while(a < m - 1){
            a++;
            start = start -> next;
        }        
        while(b < n){
            b++;
            end = end -> next;
        }
        
        temp2 = end;
        end = end -> next;
        temp2 -> next = NULL;
        
        if(m == 1){
            temp1 = start;
            head = reverse(start); 
        }
        else{
            temp1 = start -> next;
            start -> next = reverse(start -> next);
        }                
                
        temp1 -> next = end;
        return head;
    }
};
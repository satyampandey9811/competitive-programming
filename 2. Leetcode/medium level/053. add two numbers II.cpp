// link to question - https://leetcode.com/problems/add-two-numbers-ii/

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
        ListNode * temp = reverse(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return temp;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        int sum, c = 0;
        ListNode *ansh = NULL, *anst = NULL;
        
        while(l1 or l2){
            sum = 0;
            
            if(l1){
                sum = sum + l1 -> val + c;
                if(l2) 
                    sum = sum + l2 -> val;
                l1 -> val = sum % 10;
                c = sum / 10;
                
                if(ansh == NULL)
                    ansh = anst = l1;
                else{
                    anst -> next = l1;
                    anst = l1;        
                }
            }
            else{
                sum = l2 -> val + c;
                l2 -> val = sum % 10;
                c = sum / 10;
                
                if(ansh == NULL)
                    ansh= anst = l2;
                else{
                    anst -> next = l2;
                    anst = l2;
                }
            }
            if(l1) l1 = l1 -> next;
            if(l2) l2 = l2 -> next;
        }
        if(c){
            ListNode *temp = new ListNode(1);
            anst -> next = temp;            
        }
        ansh = reverse(ansh);
        return ansh;
    }
};
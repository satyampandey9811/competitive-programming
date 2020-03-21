// link to question - https://leetcode.com/problems/insertion-sort-list/

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
    ListNode* insertionSortList(ListNode* head) {
        
        if(!head or !head -> next)
            return head;
        
        ListNode *fcurr = head -> next, *fprev = head;
        
        while(fcurr){
            
            ListNode *scurr = head, *sprev = NULL;
            bool flag = false;
            
            while(scurr != fcurr){
                
                if(fcurr -> val > scurr -> val){
                    if(sprev == NULL)
                        sprev = head;
                    else
                        sprev = scurr;                    
                    scurr = scurr -> next;
                }
                
                else{
                    fprev -> next = fcurr -> next;
                    fcurr -> next = scurr;
                    
                    if(sprev == NULL)
                        head = fcurr;                            
                    else                        
                        sprev -> next = fcurr;
                    
                    flag = true;
                    break;
                }                
            }
            
            if(!flag){
                fprev = fcurr;
                fcurr = fcurr -> next;
            }
            else
                fcurr = fprev -> next;            
        }
        
        return head;
    }
};
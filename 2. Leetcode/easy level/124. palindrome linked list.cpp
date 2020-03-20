// link to question - https://leetcode.com/problems/palindrome-linked-list/

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
        
        ListNode *ans = reverse(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return ans;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *first = head, *second = head;
        
        while(first and first -> next){
            first = first -> next -> next;
            second = second -> next;
        }
        
        first = head;
        second = reverse(second);
        
        while(first and second){
            if(first -> val != second -> val)
                return false;
            first = first -> next;
            second = second -> next;
        }
        
        return true;
    }
};
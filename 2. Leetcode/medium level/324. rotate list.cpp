// link to question - https://leetcode.com/problems/rotate-list/

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode *prev = NULL, *curr = head, *next;
        
        while(curr) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode *temp = head;
        while(temp) {
            len++;
            temp = temp -> next;
        }
        if(len == 0) return head;
        k %= len;
        if(k == 0) return head;
        
        head = reverse(head);
        temp = head, len = 1;
        while(len < k) {
            len++;
            temp = temp -> next;
        }
        
        ListNode *second = reverse(temp -> next);
        temp -> next = NULL;
        temp = head;
        head = reverse(head);
        temp -> next = second;
        
        return head;
    }
};
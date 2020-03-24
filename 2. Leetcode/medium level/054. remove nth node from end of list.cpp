// link to question - https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head, *del;
        int len = 0;
        
        while(temp){
            len++;
            temp = temp -> next;
        }
        
        len -= n;
        temp = head;
        if(len == 0){
            head = head -> next;
            delete temp;
            return head;
        }
        for(int i = 0; i < len - 1; i++){            
            temp = temp -> next;
        }
        del = temp -> next;
        temp -> next = del -> next;
        delete del;
        return head;    
    }
};
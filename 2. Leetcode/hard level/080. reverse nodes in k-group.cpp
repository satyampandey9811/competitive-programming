// link to question - https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head;
        int c = 0;
        
        while(temp) {
            c++;
            temp = temp -> next;
            if(c == k) break;
        }
        if(c < k) return head;
        
        ListNode *prev = reverseKGroup(temp, k);
        ListNode *current = head, *next;
        c = 0;
        
        while(c < k) {
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
            c++;
        }
        
        return prev;
    }
};
// link to question - https://leetcode.com/problems/reverse-nodes-in-even-length-groups/

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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode *temp = head, *prev;
        int c = 0, k = 1;
        
        while(temp) {
            c++;
            if(c == k) {
                c = 0;
                if(k & 1) {
                    prev = temp;
                    temp = temp -> next;
                }
                else {
                    // reverse
                    
                    ListNode *pre = temp -> next, *cur = prev -> next, *next;
                    ListNode *actualNext = temp -> next;
                    ListNode *actualPrev = prev -> next;
                    
                    while(cur != actualNext) {
                        next = cur -> next;
                        cur -> next = pre;
                        pre = cur;
                        cur = next;
                    }
                    
                    prev -> next = pre;
                    prev = actualPrev;
                    temp = actualNext;
                }
                k++;
            }
            else temp = temp -> next;
        }
        
        if(c % 2 == 0) {
            ListNode *pre = NULL, *cur = prev -> next, *next;

            while(cur) {
                next = cur -> next;
                cur -> next = pre;
                pre = cur;
                cur = next;
            }

            prev -> next = pre;
        }
        
        return head;
    }
};
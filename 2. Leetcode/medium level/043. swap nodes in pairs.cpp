// link to question - https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        ListNode *temp = head, *store, *prev = NULL;
        if(!temp or !temp -> next)
            return head;
        head = head -> next;
        
        while(temp and temp -> next){
            store = temp -> next;
            temp -> next = store -> next;
            store -> next = temp;
            if(!prev)
                prev = temp;
            else{
                prev -> next = store;
                prev = temp;
            }
            temp = temp -> next;
        }
        
        return head;
    }
};
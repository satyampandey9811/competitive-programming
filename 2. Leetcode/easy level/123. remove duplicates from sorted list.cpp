// link to question - https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode *temp = head, *del;
        while(temp and temp -> next){
            if(temp -> val != temp -> next -> val)
                temp = temp -> next;
            else{
                del = temp -> next;
                temp -> next = temp -> next -> next;
                delete del;
            }
        }
        return head;
    }
};
// link to question - https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* first = new ListNode(-101);
        first -> next = head;
        ListNode *temp = first, *prev = NULL;
        
        while(temp) {
            if(!temp -> next) break;            
            if(temp -> val == temp -> next -> val) {
                ListNode* t = temp -> next;
                while(t and t -> val == temp -> val) {
                    t = t -> next;
                }
                prev -> next = t;
            }
            else {
                prev = temp;
            }
            temp = prev -> next;
        }
        
        return first -> next;
    }
};
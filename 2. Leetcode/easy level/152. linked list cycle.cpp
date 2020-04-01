// link to question - https://leetcode.com/problems/linked-list-cycle/

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
    bool hasCycle(ListNode *head) {
        if(!head or !head -> next) return false;
        
        ListNode *slow = head, *fast = head;
        while(fast and fast -> next){
            if(fast -> next == slow)
                return true;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return false;
    }
};
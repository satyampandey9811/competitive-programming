// link to question - https://leetcode.com/problems/reorder-list/

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
    void reorderList(ListNode* head) {
        vector<ListNode*> add;        
        int i = 0, j = add.size() - 1;
        
        while(head) {
            add.push_back(head);
            head = head -> next;
        }
         
        while(i < j - 1) {
            add[j] -> next = add[i] -> next;
            add[i] -> next = add[j];
            add[j-1] -> next = NULL;
            i++, j--;
        }
    }
};
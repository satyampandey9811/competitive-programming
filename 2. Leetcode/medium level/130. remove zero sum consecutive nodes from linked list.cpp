// link to question - https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* root = new ListNode(0);
        root -> next = head;
        unordered_map<int, ListNode*> m;
        m[0] = root;
        int ac = 0;
        
        while(head) {
            ac += head -> val;            
            
            if(m.find(ac) != m.end()) {
                ListNode* prev = m[ac];
                ListNode* start = prev;
                                
                int aux = ac;
                while(prev != head){
                    prev = prev -> next;
                    aux += prev -> val;
                    if(prev != head) m.erase(aux);
                }
                
                start -> next = head -> next;
            }
            else
                m[ac] = head;            
            
            head = head -> next;
        }        
        return root -> next;
    }
};
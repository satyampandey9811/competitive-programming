// link to question - https://leetcode.com/problems/merge-nodes-in-between-zeros/

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
    ListNode* mergeNodes(ListNode* head) {
        vector<int> s;
        int sm = 0;
        
        ListNode *temp = head -> next;
        
        while (temp) {
            if (temp -> val == 0) {
                s.push_back(sm);
                sm = 0;
            }
            else sm += temp -> val;
            temp = temp -> next;
        }
        
        ListNode *ans = new ListNode(s[0]);
        int l = s.size();
        temp = ans;
        
        for (int i = 1; i < l; i++) {
            temp -> next = new ListNode(s[i]);
            temp = temp -> next;
        }
        
        return ans;
    }
};
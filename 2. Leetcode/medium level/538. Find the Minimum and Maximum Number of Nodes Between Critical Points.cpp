// link to question - https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {INT_MAX, INT_MIN};
        int first = -1, last = -1;
        
        ListNode *temp = head -> next;
        int prev = head -> val;
        int ct = 1;
        
        while(temp and temp -> next) {
            if((temp -> val < prev and temp -> val < temp -> next -> val) or (temp -> val > prev and temp -> val > temp -> next -> val)) {
                if(first == -1) {
                    first = last = ct;
                }
                else {
                    ans[0] = min(ans[0], ct - last);
                    last = ct;
                }
            } 
            
            prev = temp -> val;
            ct++;
            temp = temp -> next;
        }
        
        if(ans[0] == INT_MAX) return {-1, -1};
        ans[1] = last - first;
        return ans;
    }
};
// link to question - https://leetcode.com/problems/linked-list-components/

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
    int numComponents(ListNode* head, vector<int>& g) {
        int ans = 0, c = 0, x;
        unordered_set<int> s(g.begin(), g.end());
        while(head != NULL) {
            x = head -> val;
            if(c == 0 and s.count(x) > 0)
                c++, ans++;            
            else if(c == 1 and s.count(x) == 0)
                c = 0;             
            head = head -> next;
        }
            
        return ans;
    }
};
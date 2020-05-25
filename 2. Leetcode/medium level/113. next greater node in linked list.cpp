// link to question - https://leetcode.com/problems/next-greater-node-in-linked-list/

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
    vector<int> nextLargerNodes(ListNode* head) {    
        auto temp = head;
        vector<int> values;
        
        while(temp != NULL) {
            values.push_back(temp -> val);
            temp = temp -> next;
        }
        
        vector<int> ans(values.size());
        stack<int> index;
        
        for(int i = 0; i < values.size(); i++) {
            while(index.size() and values[i] > values[index.top()]) {
                ans[index.top()] = values[i];
                index.pop();
            }
            index.push(i);
        }
        
        return ans;
    }
};
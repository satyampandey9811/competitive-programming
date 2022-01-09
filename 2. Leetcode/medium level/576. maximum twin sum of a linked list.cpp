// link to question - https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

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
    int pairSum(ListNode* head) {
        vector<int> store;
        ListNode *temp = head;
        
        while (temp) {
            store.push_back(temp -> val);
            temp = temp -> next;
        }
        
        int ans = 0;
        int n = store.size();
        int i = 0, j = n - 1;
        
        while (i < j) {
            ans = max(ans, store[i] + store[j]);
            i++, j--;
        }
        
        return ans;
    }
};
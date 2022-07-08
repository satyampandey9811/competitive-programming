// link to question - https://leetcode.com/problems/spiral-matrix-iv/

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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        
        while (head) {
            for (int i = left; i <= right; i++) {
                ans[top][i] = head -> val;
                head = head -> next;
                if (!head) break;
            }
            top++;
            
            if (!head) break;
            
            for (int i = top; i <= bottom; i++) {
                ans[i][right] = head -> val;
                head = head -> next;
                if (!head) break;
            }
            right--;
            
            if (!head) break;
            
            for (int i = right; i >= left; i--) {
                ans[bottom][i] = head -> val;
                head = head -> next;
                if (!head) break;
            }
            bottom--;
            
            if (!head) break;
            
            for (int i = bottom; i >= top; i--) {
                ans[i][left] = head -> val;
                head = head -> next;
                if (!head) break;
            }
            left++;
            
            if (!head) break;
        }
        
        return ans;
    }
};
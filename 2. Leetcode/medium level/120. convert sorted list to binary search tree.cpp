// link to question - https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* help(vector<int>& values, int s, int e) {
        if(s > e)
            return NULL;
        int mid = (s + e) / 2;
        TreeNode *root = new TreeNode(values[mid]);
        root -> left = help(values, s, mid - 1);
        root -> right = help(values, mid + 1, e);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> values;
        while(head != NULL) {
            values.push_back(head -> val);
            head = head -> next;
        }
        return help(values, 0, values.size() - 1);        
    }
};
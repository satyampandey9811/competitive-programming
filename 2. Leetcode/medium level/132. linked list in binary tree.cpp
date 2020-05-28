// link to question - https://leetcode.com/problems/linked-list-in-binary-tree/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:     
    bool help(ListNode* head, TreeNode* root) {
        if(!head) return 1;
        if(!root) return 0; 
        if(root -> val != head -> val) return 0;
        return help(head -> next, root -> left) or help(head -> next, root -> right);
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {      
        if(!root) return 0;
        return help(head, root) or isSubPath(head, root -> left) or isSubPath(head, root -> right);
    }
};
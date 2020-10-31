// link to question - https://leetcode.com/problems/recover-binary-search-tree/

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
    TreeNode *first, *second;
    TreeNode *prev = new TreeNode(INT_MIN);

    void go(TreeNode* root) {
        if(!root) return;
        go(root -> left);
        
        if(!first and prev -> val > root -> val) first = prev;
        if(first and prev -> val > root -> val) second = root;
        prev = root;
        
        go(root -> right);
    }
    
    void recoverTree(TreeNode* root) {
        go(root);        
        swap(first -> val, second -> val);
    }
};
// link to question - https://leetcode.com/problems/convert-bst-to-greater-tree/

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
    void go(TreeNode* root, int& val) {
        if(!root) return;
        go(root -> right, val);
        root -> val += val;
        val = root -> val;  
        go(root -> left, val);              
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int val = 0;
        go(root, val);
        return root;
    }
};
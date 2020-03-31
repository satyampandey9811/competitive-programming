// link to question - https://leetcode.com/problems/univalued-binary-tree/

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
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL) return true;
        if(root -> left and root -> val != root -> left -> val)
            return false;
        if(root -> right and root -> val != root -> right -> val)
            return false;
        return isUnivalTree(root -> left) and isUnivalTree(root -> right);
    }
};
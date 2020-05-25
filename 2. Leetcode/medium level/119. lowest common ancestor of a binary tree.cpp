// link to question - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL or root == p or root == q) 
            return root;        
        root -> left = lowestCommonAncestor(root -> left, p, q);
        root -> right = lowestCommonAncestor(root -> right, p, q);
        if(root -> left == NULL)
            return root -> right;
        else {
            if(root -> right == NULL)
                return root -> left;
            else
                return root;
        }
    }
};
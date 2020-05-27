// link to question - https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

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
    int findDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(findDepth(root -> left), findDepth(root -> right));
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {        
        if(!root)
            return NULL;
        int l = findDepth(root -> left);
        int r = findDepth(root -> right);
        if(l == r)
            return root;
        else if(l < r)
            return lcaDeepestLeaves(root -> right);
        else
            return lcaDeepestLeaves(root -> left);
    }
};
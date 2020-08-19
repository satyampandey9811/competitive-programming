// link to question - https://leetcode.com/problems/minimum-distance-between-bst-nodes/submissions/

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
    TreeNode* trimBST(TreeNode* root, int l, int r) {
        if(!root) return root;
        if(root -> val > r) return trimBST(root -> left, l, r);
        if(root -> val < l) return trimBST(root -> right, l, r);
        
        root -> left = trimBST(root -> left, l, r);
        root -> right = trimBST(root -> right, l, r);
        return root;
    }
};
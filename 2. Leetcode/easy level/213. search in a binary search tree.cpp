// link to question - https://leetcode.com/problems/search-in-a-binary-search-tree/

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
    TreeNode* searchBST(TreeNode* root, int val) {                
        if(root == NULL);
        else if(val == root -> val);            
        else if(val <= root -> val)
            return searchBST(root -> left, val);
        else
            return searchBST(root -> right, val);
        return root;
    }
};
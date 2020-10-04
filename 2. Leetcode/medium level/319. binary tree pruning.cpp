// link to question - https://leetcode.com/problems/binary-tree-pruning/

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
    bool dfs(TreeNode* root) {
        if(!root) return 1;
        bool left = dfs(root -> left);
        bool right = dfs(root -> right);
        
        if(left) root -> left = NULL;
        if(right) root -> right = NULL;
        
        if(root -> val) return 0;
        return left and right;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if(dfs(root)) {
            return NULL;    
        }  
        return root;
    }
};
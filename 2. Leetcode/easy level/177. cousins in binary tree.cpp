// link to question - https://leetcode.com/problems/cousins-in-binary-tree/

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
    int parentX, parentY, depthX, depthY;
    
    void helper(TreeNode* root, int x, int y, int parent, int depth) {
        if(root == NULL)
            return;
        if(root -> val == x) 
            parentX = parent, depthX = depth;
        else if(root -> val == y)
            parentY = parent, depthY = depth;
        
        helper(root -> left, x, y, root -> val, depth + 1);
        helper(root -> right, x, y, root -> val, depth + 1);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if(root -> val == x or root -> val == y) 
            return 0;
        helper(root, x, y, 0, 0);
        
        return depthX == depthY and parentX != parentY;
    }
};
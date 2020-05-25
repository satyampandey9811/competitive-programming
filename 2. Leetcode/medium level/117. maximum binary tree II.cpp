// link to question - https://leetcode.com/problems/maximum-binary-tree-ii/

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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root == NULL) {
            TreeNode* newroot = new TreeNode(val);
            return newroot;
        }
        if(root -> val < val) {
            TreeNode* newroot = new TreeNode(val);
            newroot -> left = root;
            return newroot;
        }        
        root -> right = insertIntoMaxTree(root -> right, val);
        return root;
    }
};
// link to question - https://leetcode.com/problems/delete-node-in-a-bst/

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        
        if(root -> val == key) {           
            if(!root -> left and !root -> right) return NULL;
            if(!root -> left) return root -> right;
            if(!root -> right) return root -> left;

            TreeNode *temp = root -> right, *prev = NULL;
            while(temp -> left) {
                prev = temp;
                temp = temp -> left;
            }   
            root -> val = temp -> val;
            if(!prev) root -> right = temp -> right;
            else prev -> left = temp -> right;            
            return root;
        }
        
        root -> left = deleteNode(root -> left, key);
        root -> right = deleteNode(root -> right, key);
        return root;
    }
};
// link to question - https://leetcode.com/problems/symmetric-tree/

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
    bool go(TreeNode* first, TreeNode* second) {
        if(first and second) {
            if(first -> val != second -> val) return 0;
            return go(first -> left, second -> right) and
                go(first -> right, second -> left);
        }
        if(first or second) return 0;
        return 1;
    }
    
    bool isSymmetric(TreeNode* root) {
        return go(root -> left, root -> right);
    }
};
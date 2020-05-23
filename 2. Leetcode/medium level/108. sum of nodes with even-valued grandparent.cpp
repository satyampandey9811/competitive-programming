// link to question - https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

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
    int sumEvenGrandparent(TreeNode* root) {
        if(root == NULL)
            return;
        int ans = 0;
        if(root -> val % 2 == 0) {
            if(root -> left and root -> left -> left) 
                ans += root -> left -> left -> val;
            if(root -> left and root -> left -> right) 
                ans += root -> left -> right -> val;
            if(root -> right and root -> right -> left) 
                ans += root -> right -> left -> val;
            if(root -> right and root -> right -> right) 
                ans += root -> right -> right -> val;
        }
        return ans + sumEvenGrandParent(root -> left) + sumEvenGrandParent(root -> right);
    }
};